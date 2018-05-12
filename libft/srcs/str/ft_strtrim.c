/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 21:01:40 by mfrisby           #+#    #+#             */
/*   Updated: 2014/12/01 16:40:34 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t		space;
	char		*str;
	size_t		before;

	if (!s)
		return (NULL);
	space = ft_strlen(s);
	before = 0;
	while (s[before] == ' ' || s[before] == '\n' || s[before] == '\t')
		before++;
	if (before == space)
		return (ft_strnew(1));
	if (space)
		space--;
	while ((s[space] == ' ' || s[space] == '\n' || s[space] == '\t') && space)
		space--;
	space = space - before;
	str = ft_strsub(s, before, space + 1);
	return (str);
}
