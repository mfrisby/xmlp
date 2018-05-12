/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:17:37 by mfrisby           #+#    #+#             */
/*   Updated: 2015/09/24 17:38:36 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*dstp;

	str = ft_strnew(len);
	str = ft_strncpy(str, src, len);
	dstp = (char*)dst;
	dst = ft_strncpy(dstp, str, len);
	free(str);
	return (dst);
}
