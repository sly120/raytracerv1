/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:44:51 by sly               #+#    #+#             */
/*   Updated: 2017/05/12 21:48:24 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			create_sph(char *file, char **str, t_param *p)
{
	char		*endptr;

//	printf("create_sph\n");
	free(*str);
	*str = get_line(file);
//	ft_putendl(*str);
	p->obj->sph.pos.x = ft_strtod(*str, &endptr);
	p->obj->sph.pos.y = ft_strtod(endptr, &endptr);
	p->obj->sph.pos.z = ft_strtod(endptr, &endptr);
	p->obj->sph.radius = ft_strtod(endptr, NULL);
	free(*str);
	*str = get_line(file);
	p->obj->ambient = ft_strtod(*str, NULL); //0x000000FF;
	free(*str);
	*str = get_line(file);
	p->obj->diffuse = ft_strtod(*str, NULL);//0x0000FF00;
//	printf("sphere x : %f, y : %f, z : %f, radius: %f, ambient: %d, diffuse: %d\n", p->obj->sph.pos.x, p->obj->sph.pos.y, p->obj->sph.pos.z, p->obj->sph.radius, p->obj->ambient, p->obj->diffuse);
	free(*str);
	p->obj->type = SPHERE;
}

void			create_light(char *file, char **str, t_param *p)
{
	char		*endptr;

//	printf("create_sph\n");
	free(*str);
	*str = get_line(file);
//	ft_putendl(*str);
	p->obj->light.pos.x = ft_strtod(*str, &endptr);
	p->obj->light.pos.y = ft_strtod(endptr, &endptr);
	p->obj->light.pos.z = ft_strtod(endptr, &endptr);
	p->obj->light.positional = ft_strtod(endptr, NULL);
	free(*str);
	*str = get_line(file);
	p->obj->ambient = ft_strtod(*str, NULL);
	free(*str);
	*str = get_line(file);
	p->obj->diffuse = ft_strtod(*str, NULL);
	free(*str);
	*str = get_line(file);
	p->obj->specular = ft_strtod(*str, NULL);
	free(*str);
	printf("light x : %f, y : %f, z : %f, ambient : %d, diffuse : %d, specular : %d\n", p->obj->light.pos.x, p->obj->light.pos.y, p->obj->light.pos.z, p->obj->ambient, p->obj->diffuse, p->obj->specular);
	p->obj->type = LIGHT;
}

void			init_obj(t_object *obj)
{
	obj->ambient = 0;
	obj->diffuse = 0;
	obj->specular = 0;
	obj->selfillum = 0;
	obj->shininess = 0;
	obj->shinestrength = 0;
	obj->transmittivity = 0;
	obj->reflectivity = 0;
	obj->permanent = 0;
	obj->t = 0;
	obj->next = NULL;
}

void			add_obj(t_param *p, int i)
{
	t_object	*new_obj;
	t_object	**obj_addr;

	if (!(new_obj = (t_object*)malloc(sizeof(t_object))))
		exit(4);
	init_obj(new_obj);
//	printf("obj ambient : %d\n", obj->ambient);
	obj_addr = &p->obj;
	new_obj->id = i;
//	printf("cursor : %p\n", cursor);
	while (*obj_addr)
		obj_addr = &(*obj_addr)->next;
	*obj_addr = new_obj;
}

void			create_obj(char *file, t_param *p)
{
	char		*str;
	int			count;

	count = 0;
	p->obj = NULL;
	while (ft_strcmp(str, ""))
	{
		str = get_line(file);
//	ft_putendl(str);
/*	free(str);
	while (str[0] != '\0')
	{
		str = get_line(file);
		ft_putendl(str);
		free(str);
	}
*/
		if (!(ft_strcmp(str, "sphere")))
		{
			add_obj(p, count++);
			create_sph(file, &str, p);
//			printf("obj : %p, sph : %d\n", p->obj, p->obj->type);
//		str = get_line(file);
//		ft_putendl(str);
		}
		else if (!(ft_strcmp(str, "light")))
		{
			add_obj(p, count++);
			create_light(file, &str, p);
		}
		str = get_line(file);
		if (!(ft_strcmp(str, "\n")))
		{
			free(str);
			str = get_line(file);
		}
	}
//	printf("fin\n");
}
