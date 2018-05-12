/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:04:20 by mfrisby           #+#    #+#             */
/*   Updated: 2015/12/08 15:47:00 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*new_content;
	size_t	new_size;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		new_content = ft_memalloc(content_size);
		ft_memcpy(new_content, content, content_size);
		new_size = content_size;
		lst->content = new_content;
		lst->content_size = new_size;
	}
	else
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	lst->next = NULL;
	return (lst);
}
