/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cache.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:57:41 by sly               #+#    #+#             */
/*   Updated: 2017/02/27 20:28:43 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			display_cache(t_param *p)
{
	int			color;
	t_vector	pos;

	pos = vector_vector_add(p->campos, vector_scalar_mult(p->rayvect, p->obj->t));
	color = 0;
	if (p->obj->t >= 0)
		color = p->obj->ambient;
	color += light_calc(pos, p);
	p->imgad[p->sl * p->y + 4 * p->x] = color;
	p->imgad[p->sl * p->y + 4 * p->x + 1] = color >> 8;
	p->imgad[p->sl * p->y + 4 * p->x + 2] = color >> 16;
}
