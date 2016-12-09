/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:47:22 by sly               #+#    #+#             */
/*   Updated: 2016/12/09 21:50:05 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_vector		vector_scalar_mult(t_vector vect, double scalar)
{
	t_vector	res;

	res.x = vect.x * scalar;
	res.y = vect.y * scalar;
	res.z = vect.z * scalar;
	return (res);
}
