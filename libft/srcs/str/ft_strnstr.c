/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:03:21 by mfrisby           #+#    #+#             */
/*   Updated: 2014/12/05 17:46:02 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if ((s2[e] == '\0' || s2 == NULL))
		return ((char *)s1);
	while ((s1[i] != '\0' && s2[e] != '\0') && i < n)
	{
		e = 0;
		while (s1[i + e] == s2[e] && s2[e] && i + e < n)
			e++;
		if (s2[e] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
