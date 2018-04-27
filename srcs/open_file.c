/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:40:27 by mfrisby           #+#    #+#             */
/*   Updated: 2018/04/27 18:17:18 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../incs/xmlp.h"

int			open_file(char *path)
{
	if (path != NULL)
		return (open(path, O_RDONLY));
	return (-1);
}