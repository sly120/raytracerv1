/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:50:13 by sly               #+#    #+#             */
/*   Updated: 2014/11/17 19:59:18 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}