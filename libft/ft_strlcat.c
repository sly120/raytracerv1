/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 20:32:23 by sly               #+#    #+#             */
/*   Updated: 2014/11/12 19:54:55 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(dst);
	if (size <= len)
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, size - len - 1);
	return (len + ft_strlen(src));
}
