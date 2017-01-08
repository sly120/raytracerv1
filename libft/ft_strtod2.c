/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:56:46 by sly               #+#    #+#             */
/*   Updated: 2017/01/08 21:24:46 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			skimoffexponent2(t_strtod *s)
{
	if (*s->p == '-')
	{
		s->expsign = TRUE;
		s->p += 1;
	}
	else
	{
		if (*s->p == '+')
			s->p += 1;
		s->expsign = FALSE;
	}
}

int				skimoffexponent(char **end, t_strtod *s)
{
	s->p = s->pexp;
	if ((*s->p == 'E') || (*s->p == 'e'))
	{
		s->p += 1;
		skimoffexponent2(s);
		if (!ft_isdigit((unsigned char)(*s->p)))
		{
			s->p = s->pexp;
			*end = (end != NULL) ? (char*)s->p : 0;
			if (s->sign)
				s->fraction = -s->fraction;
			return (TRUE);
		}
		while (ft_isdigit((unsigned char)(*s->p)))
		{
			s->exp = s->exp * 10 + (*s->p - '0');
			s->p += 1;
		}
	}
	s->exp = (s->expsign) ? s->fracexp - s->exp : s->fracexp + s->exp;
	return (FALSE);
}

double				*powersof10(void)
{
	double			*powers;

	if (!(powers = (double*)malloc(sizeof(double) * 9)))
		exit(1);
	powers[0] = 10.;
	powers[1] = 100.;
	powers[2] = 1.e4;
	powers[3] = 1.e8;
	powers[4] = 1.e16;
	powers[5] = 1.e32;
	powers[6] = 1.e64;
	powers[7] = 1.e128;
	powers[8] = 1.e256;
	return (powers);
}

void				generatedoublewithexp(t_strtod *s)
{
	if (s->exp < 0)
	{
		s->expsign = TRUE;
		s->exp = -s->exp;
	}
	else
		s->expsign = FALSE;
	if (s->exp > MAXEXPONENT)
	{
		s->exp = MAXEXPONENT;
		errno = ERANGE;
	}
	s->dblexp = 1.0;
	s->d = powersof10();
	while (s->exp != 0)
	{
		if (s->exp & 01)
			s->dblexp *= *s->d;
		s->exp >>= 1;
		s->d += 1;
	}
	s->fraction = (s->expsign) ? s->fraction / s->dblexp :
		s->fraction * s->dblexp;
//	free(s->d);
}

void				ft_strtod2(char **end, t_strtod *s)
{
	if (skimoffexponent(end, s))
		return;
	generatedoublewithexp(s);
	if (end != NULL)
		*end = (char*)s->p;
	if (s->sign)
		s->fraction = -s->fraction;
}
