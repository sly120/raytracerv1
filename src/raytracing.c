/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:47:09 by sly               #+#    #+#             */
/*   Updated: 2016/12/09 23:10:43 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		raytracing_part1(t_param *p)
{
/*	p->vplaneupleft.x = p->campos.x + p->camvec.x * p->campl.dist + p->upvect.x * p->campl.height / 2.0 + p->leftvect.x * p->campl.width / 2.0;
	p->vplaneupleft.y = p->campos.y + p->camvec.y * p->campl.dist + p->upvect.y * p->campl.height / 2.0 + p->leftvect.y * p->campl.width / 2.0;
	p->vplaneupleft.z = p->campos.z + p->camvec.z * p->campl.dist + p->upvect.z * p->campl.height / 2.0 + p->leftvect.z * p->campl.width / 2.0;
	printf("vplaneupleft.x ligne: %f\n", p->vplaneupleft.x);
	printf("vplaneupleft.y ligne: %f\n", p->vplaneupleft.y);
	printf("vplaneupleft.z ligne: %f\n", p->vplaneupleft.z);
*/	p->vplaneupleft = vector_vector_add(p->campos, vector_vector_add(vector_vector_add(vector_scalar_mult(p->camvec, p->campl.dist), vector_scalar_mult(p->upvect, p->campl.height / 2)), vector_scalar_mult(p->leftvect, p->campl.width / 2)));
/*	printf("vplaneupleft.x vect: %f\n", p->vplaneupleft.x);
	printf("vplaneupleft.y vect: %f\n", p->vplaneupleft.y);
	printf("vplaneupleft.z vect: %f\n", p->vplaneupleft.z);
	p->rayvect.x = p->vplaneupleft.x - p->x * p->leftvect.x * p->campl.width / (double)MAX_X - p->y * p->upvect.x * p->campl.height / (double)MAX_Y;
	p->rayvect.y = p->vplaneupleft.y - p->x * p->leftvect.y * p->campl.width / (double)MAX_X - p->y * p->upvect.y * p->campl.height / (double)MAX_Y;
	p->rayvect.z = p->vplaneupleft.z - p->x * p->leftvect.z * p->campl.width / (double)MAX_X - p->y * p->upvect.z * p->campl.height / (double)MAX_Y;
	printf("rayvect.x ligne: %f\n", p->rayvect.x);
	printf("rayvect.y ligne: %f\n", p->rayvect.y);
	printf("rayvect.z ligne: %f\n", p->rayvect.z);
*/	p->rayvect = vector_vector_sub(vector_vector_sub(p->vplaneupleft, vector_scalar_mult(p->leftvect, p->campl.width / MAX_X * p->x)), vector_scalar_mult(p->upvect, p->campl.height / MAX_Y * p->y));
/*	printf("rayvect.x vect: %f\n", p->rayvect.x);
	printf("rayvect.y vect: %f\n", p->rayvect.y);
	printf("rayvect.z vect: %f\n", p->rayvect.z);
*/	p->rayvectnorm = sqrt(p->rayvect.x * p->rayvect.x + p->rayvect.y * p->rayvect.y + p->rayvect.z * p->rayvect.z);
	p->rayvect.x /= p->rayvectnorm;
	p->rayvect.y /= p->rayvectnorm;
	p->rayvect.z /= p->rayvectnorm;
}

static void		raytracing_part2(t_param *p)
{
	p->sph.a = p->rayvect.x * p->rayvect.x + p->rayvect.y * p->rayvect.y + p->rayvect.z * p->rayvect.z;
	p->sph.b = 2 * p->rayvect.x * p->campos.x - 2 * p->rayvect.x * p->sph.origin.x + 2 * p->rayvect.y * p->campos.y - 2 * p->rayvect.y * p->sph.origin.y + 2 * p->rayvect.z * p->campos.z - 2 * p->rayvect.z * p->sph.origin.z;
	p->sph.c = p->campos.x * p->campos.x - 2 * p->campos.x * p->sph.origin.x + p->sph.origin.x * p->sph.origin.x + p->campos.y * p->campos.y - 2 * p->campos.y * p->sph.origin.y + p->sph.origin.y * p->sph.origin.y + p->campos.z * p->campos.z - 2 * p->campos.z * p->sph.origin.z + p->sph.origin.z * p->sph.origin.z - p->sph.radius * p->sph.radius;
	p->sph.det = p->sph.b * p->sph.b - 4 * p->sph.a * p->sph.c;
	if (p->sph.det >= 0)
	{
		p->sph.t1 = -p->sph.b / 2 / p->sph.a - sqrt(p->sph.det) / 2 / p->sph.a;
		p->sph.t2 = -p->sph.b / 2 / p->sph.a + sqrt(p->sph.det) / 2 / p->sph.a;
		p->sph.t = (p->sph.t1 <= p->sph.t2) ? p->sph.t1 : p->sph.t2;
	}
	else
		p->sph.t = -1;
}

void			raytracing(t_param *p)
{
	while (p->x < 2)
	{
		while (p->y < 2)
		{
			raytracing_part1(p);
//			raytracing_part2(p);
//			display_cache(p);
			p->y++;
		}
		p->x++;
		p->y = 0;
	}
//	p->x = 0;
//	hook(p);
}
