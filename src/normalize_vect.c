/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:14:17 by sly               #+#    #+#             */
/*   Updated: 2016/12/14 18:21:30 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_vector	vector_scalar_divide(t_vector vect, double scalar)
{
	vect.x /= scalar;
	vect.y /= scalar;
	vect.z /= scalar;
	return (vect);
}

t_vector		normalize_vect(t_vector vect)
{
	double		vectlen;

	vectlen = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
	return (vector_scalar_divide(vect, vectlen));
}
