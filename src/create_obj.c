/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:44:51 by sly               #+#    #+#             */
/*   Updated: 2017/02/06 21:50:12 by sly              ###   ########.fr       */
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
//	free(*str);
}

void			init_obj(void)
{
	t_object	*o;
}

void			create_obj(char *file, t_param *p)
{
	char		*str;
	t_object	*o;

	init_obj();
	str = get_line(file);
	ft_putendl(str);
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
		create_sph(file, &str, p);
//		str = get_line(file);
//		ft_putendl(str);
	}
	else
		error(6);
	free(str);
}

