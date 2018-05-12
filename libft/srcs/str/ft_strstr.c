/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:33:44 by mfrisby           #+#    #+#             */
/*   Updated: 2014/11/20 16:12:15 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int e;

	i = 0;
	e = 0;
	if (*s2 == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0' && s2[e] != '\0')
	{
		e = 0;
		while (s1[i + e] == s2[e] && s2[e])
			e++;
		if (s2[e] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
