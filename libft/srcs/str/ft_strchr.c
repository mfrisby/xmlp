/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:04:15 by mfrisby           #+#    #+#             */
/*   Updated: 2014/11/24 13:34:50 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)&c;
	if (*str == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char*)s + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == *str)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
