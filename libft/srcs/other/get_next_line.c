/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:01:56 by mfrisby           #+#    #+#             */
/*   Updated: 2015/03/03 10:57:44 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../../includes/libft.h"

static void	rotate(char *buf, size_t buf_size, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i < buf_size)
	{
		if (i + n < buf_size)
			buf[i] = buf[i + n];
		else
			buf[i] = '\0';
		i++;
	}
}

static int	get_line(char *buf, char **line)
{
	char	*str;
	char	bin;
	int		end;
	size_t	len;
	size_t	size;

	end = ft_memchr(buf, '\n', BUF_SIZE) ? 1 : 0;
	bin = end ? '\n' : '\0';
	len = (char*)ft_memchr(buf, bin, BUF_SIZE + 1) - buf + 1;
	size = *line ? ft_strlen(*line) : 0;
	if (!(str = ft_strnew(len + size)))
		return (-1);
	if (*line)
	{
		ft_strcpy(str, *line);
		free(*line);
	}
	ft_memcpy(str + size, buf, len - 1);
	*line = str;
	rotate(buf, BUF_SIZE, len);
	return (end);
}

int			get_next_line(int fd, char **line)
{
	int				ret2;
	int				ret;
	static char		buf[BUF_SIZE + 1];
	size_t			size;

	if (BUF_SIZE > 0 && line && fd >= 0)
	{
		*line = NULL;
		if ((ret = get_line(buf, line)) != 0)
			return (ret);
		size = ft_strlen(buf);
		while ((ret2 = read(fd, buf + size, BUF_SIZE - size)) > 0)
		{
			if ((ret = get_line(buf, line)) != 0)
				return (ret);
		}
		if (!ret2 && **line)
			return (1);
		if (ret2 < 0)
			return (-1);
		ft_memset(buf, 0, BUF_SIZE);
		return (0);
	}
	return (-1);
}
