/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:56:46 by sly               #+#    #+#             */
/*   Updated: 2017/01/04 00:15:28 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				skimoffexponent(char **end, t_strtod *s)
{
	s->p = s->pexp;
	if ((*s->p == 'E') || (*s->p == 'e'))
	{
		s->p += 1;
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
		if (!ft_isdigit((unsigned char)(*s->p)))
		{
			s->p = s->pexp;
			*end = (end != NULL) ? (char*)s->p : 0;
			if (s->sign)
				s->fraction = -s->fraction;
			return (1);
		}
	}
	return (0);
}

int					ft_strtod2(const char *str, char **end, t_strtod *s)
{
	skimoffexponent(end, s);
}
