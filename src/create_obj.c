/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:44:51 by sly               #+#    #+#             */
/*   Updated: 2017/02/18 18:21:19 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void			create_sph(char *file, char **str, t_param *p)
{
	char		**sph_data;

	printf("create_sph\n");
	free(*str);
	*str = get_line(file);
	ft_putendl(*str);
	sph_data = ft_strsplit(*str, ' ');
	free(*str);
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
	t_object	*obj;
	t_object	*cursor;
	char		id;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		exit(4);
	init_obj(obj);
	cursor = p->obj;
	id = 0;
	if (cursor == NULL)
	{
		obj->id = 0;
		cursor = obj;
	}
	else
	{
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
			id++;
		}
		obj->id = id;
		cursor->next = obj;
	}
}

void			create_obj(char *file, t_param *p)
{
	char		*str;

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
			add_obj(p, 0);
			create_sph(file, &str, p);
//		str = get_line(file);
//		ft_putendl(str);
		}
		str = get_line(file);
		if (!(ft_strcmp(str, "\n")))
		{
			free(str);
			str = get_line(file);
		}
	}
	printf("fin\n");
}
