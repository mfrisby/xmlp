/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:28:58 by mfrisby           #+#    #+#             */
/*   Updated: 2015/04/03 16:32:57 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_countab(char const *s, char c)
{
	int i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	size++;
	return (size);
}

int		ft_countchar(char const *s, char c, int *i)
{
	int		count;

	count = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*i)++;
		count++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		size;
	int		j;
	int		count;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	size = ft_countab(s, c);
	tab = ft_memalloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (s[i] != '\0' && j < size - 1)
	{
		count = ft_countchar(s, c, &i);
		i = i - count;
		tab[j] = ft_strsub(s, i, count);
		j++;
		i = i + count + 1;
	}
	return (tab);
}
