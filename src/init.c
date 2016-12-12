/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:28:59 by sly               #+#    #+#             */
/*   Updated: 2016/12/12 21:41:52 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		initvalues(t_param *p)
{
	p->screen.width = 0.5;
	p->screen.height = 0.5;
	p->screen.dist = 1.0;
	p->campos.x = -30;
	p->campos.y = 0;
	p->campos.z = 0;
	p->screen_vec.x = 1;
	p->screen_vec.y = 0;
	p->screen_vec.z = 0;
	p->upvect.x = 0;
	p->upvect.y = 0;
	p->upvect.z = 1;
	p->leftvect.x = 0;
	p->leftvect.y = 1;
	p->leftvect.z = 0;
	p->x = 0;
	p->y = 0;
	p->obj.id = 0;
	p->obj.sph.pos.x = 0;
	p->obj.sph.pos.y = 0;
	p->obj.sph.pos.z = 0;
	p->obj.sph.radius = 2;
	p->obj.color = 0x00FF0000;
}

void			init(char *arg, t_param *p)
{
	initvalues(p);
}
