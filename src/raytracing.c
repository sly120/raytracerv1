/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:47:09 by sly               #+#    #+#             */
/*   Updated: 2016/11/28 21:44:40 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		raytracing_part1(t_param *p)
{
	
}

void			raytracing(t_param *p)
{
	while (p->x < MAX_X)
	{
		raytracing_part1(p);
		x++;
	}
}