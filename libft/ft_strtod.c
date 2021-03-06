/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:40:07 by sly               #+#    #+#             */
/*   Updated: 2017/02/01 16:40:19 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			stripoffblankschecksign(t_strtod *s)
{
	while (ft_isspace((unsigned char)(*s->p)))
		s->p += 1;
	if (*s->p == '-')
	{
		s->sign = TRUE;
		s->p += 1;
	}
	else
	{
		if (*s->p == '+')
			s->p += 1;
		s->sign = FALSE;
	}
}

void			mantisdigitsnblocatepoint(t_strtod *s)
{
	s->decpt = -1;
	s->mantsize = 0;
	while (1)
	{
		s->c = *s->p;
		if (!ft_isdigit(s->c))
		{
			if ((s->c != '.') || (s->decpt >= 0))
				break;
			s->decpt = s->mantsize;
		}
		s->p += 1;
		s->mantsize += 1;
	}
}

void			suckupdigits2(t_strtod *s)
{
	while (s->mantsize > 9)
	{
		s->c = *s->p;
		s->p += 1;
		if (s->c == '.')
		{
			s->c = *s->p;
			s->p += 1;
		}
		s->frac1 = 10 * s->frac1 + (s->c - '0');
		s->mantsize -= 1;
	}
	while (s->mantsize > 0)
	{
		s->c = *s->p;
		s->p += 1;
		if (s->c == '.')
		{
			s->c = *s->p;
			s->p += 1;
		}
		s->frac2 = 10 * s->frac2 + (s->c - '0');
		s->mantsize -= 1;
	}
	s->fraction = (1.0e9 * s->frac1) + s->frac2;
}

int			suckupdigits(const char *str, char **end, t_strtod *s)
{
	s->pexp = s->p;
	s->p -= s->mantsize;
	if (s->decpt < 0)
		s->decpt = s->mantsize;
	else
		s->mantsize -= 1;
	if (s->mantsize > 18)
	{
		s->fracexp = s->decpt - 18;
		s->mantsize = 18;
	}
	else
		s->fracexp = s->decpt - s->mantsize;
	if (s->mantsize == 0)
	{
		s->fraction = 0.0;
		s->p = (char*)str;
		if (end != NULL)
			*end = (char*)s->p;
		return (TRUE);
	}
	else
		suckupdigits2(s);
	return (FALSE);
}

double			ft_strtod(const char *str, char **end)
{
	t_strtod	s;

	s.expsign = FALSE;
	s.exp = 0;
	s.fracexp = 0;
	s.frac1 = 0;
	s.frac2 = 0;
	s.p = (char*)str;
	stripoffblankschecksign(&s);
	mantisdigitsnblocatepoint(&s);
	if (suckupdigits(str, end, &s))
		return (s.fraction);
	ft_strtod2(end, &s);
	return(s.fraction);
}
