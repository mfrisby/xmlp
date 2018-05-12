/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_balise_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:06:15 by mfrisby           #+#    #+#             */
/*   Updated: 2018/05/12 16:35:14 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

char		*get_balise_content(char *s, int i)
{
	int len;
	char *content;

	if (!s || !s[i])
		return (NULL);
	len = 0;
	while (s && s[len] && s[len] != '<')
	{
		len++;
	}
	content = malloc(len);
	len = 0;
	while (s && s[len] && s[len] != '<')
	{
		content[len] = s[len];
		len++;
	}
	content[len] = '\0';
	return (content);
}