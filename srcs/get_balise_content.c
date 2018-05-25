/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:06:15 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/25 15:01:53 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

char		*get_balise_content(char *s, int i)
{
	int		len;
	char	*content;

	if (!s || !s[i])
		return (NULL);
	len = 0;
	while (s && s[len] && s[len] != '<')
	{
		len++;
	}
	content = malloc(len + 1);
	len = 0;
	while (s && s[len] && s[len] != '<')
	{
		content[len] = s[len];
		len++;
	}
	content[len] = '\0';
	return (content);
}
