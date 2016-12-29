/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:44:32 by sly               #+#    #+#             */
/*   Updated: 2016/12/29 21:51:48 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				light_calc(t_vector pos, t_param *p)
{
	t_vector	lightvect;
	t_vector	normal;
	double		diff_ang;
	t_color		c;
	int			color;

	color = 0;
/*	lightvect = normalize_vect(vector_vector_sub(p->light.pos, pos));
	normal = normalize_vect(vector_vector_sub(pos, p->obj.sph.pos));
	diff_ang = lightvect.x * normal.x + lightvect.y * normal.y + lightvect.z * normal.z;
	if (diff_ang > 0)
	{
		c.b = ((p->obj.diffuse & 0xFF) / 255) * ((p->light.color & 0xFF) / 255) * p->light.selfillum * diff_ang;
		c.g = (((p->obj.diffuse >> 8) & 0xFF) / 255) * (((p->light.color >> 8) & 0xFF) / 255) * p->light.selfillum * diff_ang;
		c.r = (((p->obj.diffuse >> 16) & 0xFF) / 255) * (((p->light.color >> 16) & 0xFF) / 255) * p->light.selfillum * diff_ang;
//		printf("%d\n", (p->light.color >> 16) & 0xFF);
		color = (((char)(c.r * 255) & 0xFF) << 16) | (((char)(c.g * 255) & 0xFF) << 8) | ((char)(c.b * 255) & 0xFF);
	}
*/	return (color);
}
