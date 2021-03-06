/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 21:37:30 by sly               #+#    #+#             */
/*   Updated: 2014/11/15 22:21:46 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 == *s2) && *s1)
		s1++, s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
