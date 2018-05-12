/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:11:22 by mfrisby           #+#    #+#             */
/*   Updated: 2014/11/24 14:32:56 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*adresse;
	char	*chaine;
	size_t	i;

	i = 0;
	adresse = (void*)malloc(size);
	chaine = (char*)adresse;
	if (adresse != NULL)
	{
		while (i < size)
		{
			chaine[i] = 0;
			i++;
		}
		return (adresse);
	}
	return (NULL);
}
