/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:35:59 by sly               #+#    #+#             */
/*   Updated: 2016/12/30 01:17:57 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		mlx_initialization(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, MAX_X, MAX_Y, "Wolf3D");
	p->img = mlx_new_image(p->mlx, MAX_X, MAX_Y);
	p->imgad = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	if (p->bpp != 32 || p->endian != 0)
		error(1);
}

int				main(int argc, char **argv)
{
	t_param		p;

	if (argc == 2)
	{
		mlx_initialization(&p);
		init(argv[1], &p);
		ft_strtod("1", NULL);
//		raytracing(&p);
	}
	else
		error(2);
	return (0);
}
