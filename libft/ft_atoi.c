/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:17:58 by sly               #+#    #+#             */
/*   Updated: 2014/12/01 05:33:35 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int			ft_atoi(const char *str)
{
	int		neg;
	int		res;

	neg = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1, str++;
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
		return (res * neg);
	}
	return (0);
}
