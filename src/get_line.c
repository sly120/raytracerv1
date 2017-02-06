/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:29:05 by sly               #+#    #+#             */
/*   Updated: 2017/02/06 21:34:42 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

char			*get_line(char *s)
{
	static int	end = 0;
	int			i;
	int			j;
	int			len;
	char		*str;

	i = end;
	j = 0;
	while (s[end] != '\n' && s[end] != '\0')
		end++;
	len = end - i;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		error(4);
	if (s[end] == 0)
	{
		str[0] = '\0';
		return (str);
	}
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	if (s[end] == '\n')
		end++;
	return (str);
}

