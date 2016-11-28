/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:28:59 by sly               #+#    #+#             */
/*   Updated: 2016/11/28 20:50:54 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		initvalues(t_param *p)
{
	p->campl.width = 0.35;
	p->campl.height = 0.5;
	p->campl.dist = 1.0;
	p->campos.x = 200;
	p->campos.y = 0;
	p->campos.z = 0;
	p->camvec.x = -1;
	p->camvec.y = 0;
	p->camvec.z = 0;
	p->x = 0;
	p->y = 0;
}

void			init(char *arg, t_param *p)
{
	initvalues(p);
}
