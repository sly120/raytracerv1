/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:38:43 by sly               #+#    #+#             */
/*   Updated: 2017/02/09 17:13:46 by sly              ###   ########.fr       */
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
#include <float.h>

#define MAX_X 1000
#define MAX_Y 1000

#define KEY_ARROW_UP 126
#define KEY_ARROW_DOWN 125
#define KEY_ARROW_LEFT 123
#define KEY_ARROW_RIGHT 124
#define KEY_ESC 53
#define KEY_SPACE 49
#define KEY_ENTER 36

typedef struct			s_screen
{
	double				width;
	double				height;
	double				dist;
}						t_screen;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_sphere
{
	t_vector			pos;
	double				radius;
	double				a;
	double				b;
	double				c;
	double				det;
	double				t1;
	double				t2;
}						t_sphere;

typedef struct			s_object
{
	char				id;
//	char				*name;
//	char				type;
	int					ambient;
	int					diffuse;
	int					specular;
	int					selfillum;
	double				shininess;
	double				shinestrength;
	double				transmittivity;
	double				reflectivity;
	char				permanent;
	double				t;
	t_sphere			sph;
	struct s_object		*next;
}						t_object;

typedef struct			s_light
{
	char				id;
	double				selfillum;
	int					color;
	t_vector			pos;
}						t_light;

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_param
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*imgad;
	int					bpp;
	int					sl;
	int					endian;
	t_screen			screen;
	t_vector			campos;
	t_vector			screen_vec;
	int					x;
	int					y;
	t_vector			vplaneupleft;
	t_vector			upvect;
	t_vector			leftvect;
	t_vector			rayvect;
	t_object			*obj;
	t_light				light;
}						t_param;

void					error(int err);
void					init(char *arg, t_param *p);
char					*get_line(char *s);
void					create_obj(char *file, t_param *p);
t_vector				vector_scalar_mult(t_vector vect, double scalar);
t_vector				vector_vector_add(t_vector v1, t_vector v2);
t_vector				vector_vector_sub(t_vector v1, t_vector v2);
void					raytracing(t_param *p);
t_vector				normalize_vect(t_vector vect);
int						light_calc(t_vector pos, t_param *p);
void					display_cache(int firstobjid, t_param *p);
void					hook(t_param *p);
int						key_event(int key, t_param *p);
int						quit_program(t_param *p);
#	endif
