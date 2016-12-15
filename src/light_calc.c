/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:44:32 by sly               #+#    #+#             */
/*   Updated: 2016/12/15 15:32:11 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				light_calc(t_vector pos, t_param *p)
{
	t_vector	lightvect;
	t_vector	normal;
	double		diff_ang;
	char		r;
	char		g;
	char		b;
	int			color;

	color = 0;
	lightvect = normalize_vect(vector_vector_sub(p->light.pos, pos));
	normal = normalize_vect(vector_vector_sub(pos, p->obj.sph.pos));
	diff_ang = lightvect.x * normal.x + lightvect.y * normal.y + lightvect.z * normal.z;
	if (diff_ang > 0)
	{
		//color = p->obj.diffuse * p->light.color * p->light.selfillum * diff_ang;
		r = 255 * diff_ang;
		g = 255 * diff_ang;
		b = 255 * diff_ang;
		color = r;
		color = color << 8;
		color += g;
		color = color << 8;
		color += b;
	}
	return (color);
}
