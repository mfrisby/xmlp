/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 14:58:50 by mfrisby           #+#    #+#             */
/*   Updated: 2015/09/30 16:58:40 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_countblank(char const *s)
{
	int i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
		{
			size++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	size++;
	return (size);
}

int		ft_countmore(char const *s, int *i)
{
	int		count;

	count = 0;
	while ((s[*i] == '\t' || s[*i] == ' ') && s[*i] != '\0')
		(*i)++;
	while (s[*i] != ' ' && s[*i] != '\t' && s[*i] != '\0')
	{
		(*i)++;
		count++;
	}
	return (count);
}

char	**ft_splitblank(char const *s)
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
	size = ft_countblank(s);
	tab = ft_memalloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	j = 0;
	while (s[i] != '\0' && j < size - 1)
	{
		count = ft_countmore(s, &i);
		i = i - count;
		tab[j] = ft_strsub(s, i, count);
		j++;
		i = i + count + 1;
	}
	return (tab);
}
