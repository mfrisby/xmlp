/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:25:35 by mfrisby           #+#    #+#             */
/*   Updated: 2014/11/24 13:38:48 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	str;

	i = ft_strlen(s);
	str = (char)c;
	while (i > 0 && s[i] != str)
		i--;
	if (s[i] == str)
		return ((char*)s + i);
	return (NULL);
}
