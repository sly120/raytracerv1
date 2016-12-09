/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:28:59 by sly               #+#    #+#             */
/*   Updated: 2016/12/09 22:22:40 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		initvalues(t_param *p)
{
	p->campl.width = 0.35;
	p->campl.height = 0.5;
	p->campl.dist = 1.0;
	p->campos.x = -1000;
	p->campos.y = 0;
	p->campos.z = 0;
	p->camvec.x = 1;
	p->camvec.y = 0;
	p->camvec.z = 0;
	p->upvect.x = 0;
	p->upvect.y = 0;
	p->upvect.z = 1;
	p->leftvect.x = 0;
	p->leftvect.y = 1;
	p->leftvect.z = 0;
	p->x = 0;
	p->y = 0;
	p->sph.origin.x = 0;
	p->sph.origin.y = 0;
	p->sph.origin.z = 0;
	p->sph.radius = 1;
}

void			init(char *arg, t_param *p)
{
	initvalues(p);
}
