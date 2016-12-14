/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:44:32 by sly               #+#    #+#             */
/*   Updated: 2016/12/14 23:45:17 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int				light_calc(t_vector pos, t_param *p)
{
	t_vector	lightvect;
	t_vector	normal;
	double		diff_ang;
	int			color;

	lightvect = vector_vector_sub(pos, p->light.pos);
	lightvect = normalize_vect(lightvect);
	diff_ang = acos(lightvect.x * pos.x + lightvect.y * pos.y + lightvect.z * pos.z);
	if (diff_ang > 0)
		color = p->obj.diffuse * p->light.color * p->light.selfillum * diff_ang;
	else
		color = p->obj.ambient;
	return (color);
}
