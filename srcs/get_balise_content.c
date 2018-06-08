/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:06:15 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/01 16:48:41 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

static int	get_len(char *s, int i)
{
	int len;

	len = 0;
	while (s && s[i] && s[i] != '<')
	{
		i++;
		len++;
	}
	return (len);
}

char		*get_balise_content(char *s, int i)
{
	int		y;
	int		len;
	char	*content;

	if (!s || !s[i])
		return (NULL);
	y = 0;
	len = get_len(s, i);
	if (len <= 0)
		return (NULL);
	content = ft_strnew(len + 1);
	while (y < len)
	{
		content[y] = s[i];
		y++;
		i++;
	}
	content[y] = '\0';
	return (content);
}
