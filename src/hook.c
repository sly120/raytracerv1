/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:05:08 by sly               #+#    #+#             */
/*   Updated: 2016/12/09 21:32:11 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			hook(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
//	p->legend ? display_legend(p) : mlx_string_put(p->mlx, p->win, 0, 0,
//			0x0000FFFF, "legends: space");
	mlx_key_hook(p->win, key_event, p);
	mlx_hook(p->win, 17, 17, quit_program, p);
//	mlx_hook(p->win, MOTIONNOTIFY, POINTERMOTIONMASK, turn, p);
	mlx_loop(p->mlx);
}
