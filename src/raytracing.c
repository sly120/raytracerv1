/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:47:09 by sly               #+#    #+#             */
/*   Updated: 2017/05/09 20:41:51 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		raytracing_part1(t_param *p)
{
	t_vector	screenpos;

	p->vplaneupleft = vector_vector_add(p->campos, vector_vector_add(vector_vector_add(vector_scalar_mult(p->screen_vec, p->screen.dist), vector_scalar_mult(p->upvect, p->screen.height / 2)), vector_scalar_mult(p->leftvect, p->screen.width / 2)));
	screenpos = vector_vector_sub(vector_vector_sub(p->vplaneupleft, vector_scalar_mult(p->leftvect, p->screen.width / MAX_X * p->x)), vector_scalar_mult(p->upvect, p->screen.height / MAX_Y * p->y));
	p->rayvect = vector_vector_sub(screenpos, p->campos);
/*	p->rayvectnorm = sqrt(p->rayvect.x * p->rayvect.x + p->rayvect.y * p->rayvect.y + p->rayvect.z * p->rayvect.z);
	p->rayvect.x /= p->rayvectnorm;
	p->rayvect.y /= p->rayvectnorm;
	p->rayvect.z /= p->rayvectnorm;

*/	p->rayvect = normalize_vect(p->rayvect);
}

static void		sphere_calc(t_param *p)
{
	p->obj->sph.a = p->rayvect.x * p->rayvect.x + p->rayvect.y * p->rayvect.y + p->rayvect.z * p->rayvect.z;
	p->obj->sph.b = 2 * p->rayvect.x * p->campos.x - 2 * p->rayvect.x * p->obj->sph.pos.x + 2 * p->rayvect.y * p->campos.y - 2 * p->rayvect.y * p->obj->sph.pos.y + 2 * p->rayvect.z * p->campos.z - 2 * p->rayvect.z * p->obj->sph.pos.z;
	p->obj->sph.c = p->campos.x * p->campos.x - 2 * p->campos.x * p->obj->sph.pos.x + p->obj->sph.pos.x * p->obj->sph.pos.x + p->campos.y * p->campos.y - 2 * p->campos.y * p->obj->sph.pos.y + p->obj->sph.pos.y * p->obj->sph.pos.y + p->campos.z * p->campos.z - 2 * p->campos.z * p->obj->sph.pos.z + p->obj->sph.pos.z * p->obj->sph.pos.z - p->obj->sph.radius * p->obj->sph.radius;
	p->obj->sph.det = p->obj->sph.b * p->obj->sph.b - 4 * p->obj->sph.a * p->obj->sph.c;
	if (p->obj->sph.det >= 0)
	{
		p->obj->sph.t1 = -p->obj->sph.b / 2 / p->obj->sph.a - sqrt(p->obj->sph.det) / 2 / p->obj->sph.a;
		p->obj->sph.t2 = -p->obj->sph.b / 2 / p->obj->sph.a + sqrt(p->obj->sph.det) / 2 / p->obj->sph.a;
		p->obj->t = (p->obj->sph.t1 <= p->obj->sph.t2) ? p->obj->sph.t1 : p->obj->sph.t2;
//		if (p->obj->t >= 0)
//			printf("x: %d, y:%d, det: %f, t: %f, t1: %f, t2: %f, a: %f, b: %f, c: %f\n", p->x, p->y, p->obj->sph.det, p->obj->t, p->obj->sph.t1, p->obj->sph.t2, p->obj->sph.a, p->obj->sph.b, p->obj->sph.c);
	}
	else
		p->obj->t = -1;
}

static void		raytracing_part2(t_param *p)
{
//	printf("type: %d\n", p->obj->type);
	if (p->obj->type == SPHERE)
		sphere_calc(p);
	display_cache(p);
}

void			raytracing(t_param *p)
{
	while (p->x < MAX_X)
	{
		while (p->y < MAX_Y)
		{
			raytracing_part1(p);
			raytracing_part2(p);
			p->y++;
		}
		p->x++;
		p->y = 0;
	}
	p->x = 0;
//	printf("rayvect: %f, vplaneupleft: %f\n", p->rayvect.x, p->vplaneupleft.x);
	hook(p);
}
