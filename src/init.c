/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:28:59 by sly               #+#    #+#             */
/*   Updated: 2017/05/09 20:50:08 by sly              ###   ########.fr       */
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
	p->obj->id = 0;
//	p->obj.sph.pos.x = 0;
//	p->obj.sph.pos.y = 0;
//	p->obj.sph.pos.z = 0;
//	p->obj->sph.radius = 2;
//	p->obj->ambient = 0x000000FF;
//	p->obj->diffuse = 0x0000FF00;
	p->light.pos.x = -20;
	p->light.pos.y = 20;
	p->light.pos.z = 20;
	p->light.selfillum = 1;
	p->light.color = 0x00FFFFFF;

}

char			*copy_file(char *file, int size)
{
	int			fd;
	char		*str;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(3);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		error(4);
	if ((read(fd, str, size - 1)) == -1)
		error(5);
	str[size] = '\0';
	close(fd);
	return (str);
}

int				open_file(char* file)
{
	int			fd;
	int			ret;
	int			size;
	char		c;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(3);
	size = 0;
	ret = 1;
	while (ret)
	{
		if ((ret = read(fd, &c, 1)) == -1)
			error(5);
		if (!(ft_isalnum(c) || c == '\n' || c == '\0' || c == '-' || c == ' ' ||
					c == '{' || c == '}' || c == '.' || c == '<' || c == '>'))
		{
			ft_putchar(c);
			error(6);
		}
		size++;
//	printf("size: %d, ret:%d\n", size, ret);
	}
	close(fd);
	return (size);
}

void			init(char *arg, t_param *p)
{
	int			fsize;
	char		*file;

	fsize = open_file(arg);
	file = copy_file(arg, fsize);
//	ft_putendl(file);
//	printf("file read\n");
	create_obj(file, p);
	initvalues(p);
	free(file);
}
