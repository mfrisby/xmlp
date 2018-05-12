/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 20:41:04 by mfrisby           #+#    #+#             */
/*   Updated: 2015/04/03 16:24:28 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s) || len > (ft_strlen(s) - start))
		return (NULL);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			str[i - start] = s[i];
		i++;
	}
	return (str);
}
