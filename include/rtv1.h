/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:38:43 by sly               #+#    #+#             */
/*   Updated: 2016/12/01 22:55:48 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RTV1_H
#define RTV1_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <OpenCL/opencl.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include <libft.h>

#define MAX_X 500
#define MAX_Y 500

#define KEY_ARROW_UP 126
#define KEY_ARROW_DOWN 125
#define KEY_ARROW_LEFT 123
#define KEY_ARROW_RIGHT 124
#define KEY_ESC 53
#define KEY_SPACE 49
#define KEY_ENTER 36

typedef struct			s_camplane
{
	double				width;
	double				height;
	double				dist;
}						t_camplane;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_sphere
{
	t_vector			origin;
	double				radius;
	double				a;
	double				b;
	double				c;
	double				det;
	double				t1;
	double				t2;
}						t_sphere;

typedef struct			s_param
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*imgad;
	int					bpp;
	int					sl;
	int					endian;
	t_camplane			campl;
	t_vector			campos;
	t_vector			camvec;
	int					x;
	int					y;
	t_vector			vplaneupleft;
	t_vector			upvect;
	t_vector			leftvect;
	t_vector			rayvect;
	double				rayvectnorm;
	t_sphere			s1;
}						t_param;

void					init(char *arg, t_param *p);
void					raytracing(t_param *p);
#	endif
