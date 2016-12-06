/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cache.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:57:41 by sly               #+#    #+#             */
/*   Updated: 2016/12/06 23:03:23 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			display_cache(t_param *p)
{
	int			color;

	if (p->sph.t == -1)
		color = 0;
	else
		color = 0x00FF0000;
	p->imgad[p->sl * p->y + 4 * p->x] = color;
	p->imgad[p->sl * p->y + 4 * p->x + 1] = color >> 8;
	p->imgad[p->sl * p->y + 4 * p->x + 2] = color >> 16;
}
