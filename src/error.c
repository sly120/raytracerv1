/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 01:57:21 by sly               #+#    #+#             */
/*   Updated: 2017/02/06 16:16:53 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void		error(int err)
{
	if (err == 1)
		ft_putendl_fd(
				"This program doesn't work on this computer. Program stopped.",
				2);
	else if (err == 2)
		ft_putendl_fd("Please enter the path to a scene file. Program stopped.",
				2);
	else if (err == 3)
		ft_putendl_fd("Error at file opening. Program stopped.", 2);
	else if (err == 4)
		ft_putendl_fd("Error at memory allocating. Program stopped.", 2);
	else if (err == 5)
		ft_putendl_fd("Error at reading file. Program stopped.", 2);
	else if (err == 6)
		ft_putendl_fd(
				"File content error, no corresponding object. Program stopped."
				, 2);
	exit(1);
}
