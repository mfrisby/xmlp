/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:42:03 by mfrisby           #+#    #+#             */
/*   Updated: 2014/12/27 17:11:28 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srcs;
	size_t	dsts;
	size_t	i;

	dsts = ft_strlen(dst);
	srcs = ft_strlen(src);
	i = 0;
	if (dsts >= size)
		return (srcs + size);
	if (!size)
		return (dsts + srcs);
	while (i < size - dsts - 1 && i < srcs)
	{
		dst[dsts + i] = src[i];
		i++;
	}
	dst[dsts + i] = '\0';
	return (dsts + srcs);
}
