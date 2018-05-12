/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:51:26 by mfrisby           #+#    #+#             */
/*   Updated: 2014/12/01 19:18:42 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	while (i < n && str2[i] != (unsigned char)c)
	{
		str1[i] = str2[i];
		i++;
	}
	if (n > i)
	{
		str1[i] = str2[i];
		return (str1 + i + 1);
	}
	return (NULL);
}
