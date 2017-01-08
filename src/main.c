/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:35:59 by sly               #+#    #+#             */
/*   Updated: 2017/01/08 21:25:10 by sly              ###   ########.fr       */
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

/*int				main(int argc, char **argv)
{
	t_param		p;

	if (argc == 2)
	{
		mlx_initialization(&p);
		init(argv[1], &p);
//		raytracing(&p);
	}
	else
		error(2);
	return (0);
}*/

#include <sys/errno.h>

int			main(void)
{
	const char	*p = "111.11 -22.2 1.18e+4";
	char		*end;
	double		f;
	double		d;

	printf("parsing '%s':\n", p);
	f = ft_strtod(p, &end);
	d = strtod(p, &end);
	while (p != end)
	{
		printf("'%.*s' -> ", (int)(end-p), p);
		p = end;
		if (errno == ERANGE)
		{
			printf("range error, got ");
			errno = 0;
		}
		printf("ft: %f, std: %f\n", f, d);
	}
	return (0);
}
