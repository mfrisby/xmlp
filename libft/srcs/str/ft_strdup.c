/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:26:17 by mfrisby           #+#    #+#             */
/*   Updated: 2015/04/09 15:47:16 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;

	i = 0;
	i = ft_strlen(s1);
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new = ft_strcpy(new, s1);
	return (new);
}
