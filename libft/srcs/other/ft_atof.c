/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:45:40 by mfrisby           #+#    #+#             */
/*   Updated: 2018/03/13 14:46:15 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static double	get_div(int i, char *p, double nbr)
{
	double		d;

	d = 1.0;
	i++;
	while (p[i] && p[i] >= '0' && p[i] <= '9')
	{
		nbr = nbr * 10 + (p[i] - '0');
		d *= 10.0;
		p++;
	}
	if (d >= 10)
		nbr /= d;
	return (nbr);
}

double			ft_atof(char *p)
{
	int			isneg;
	int			i;
	double		nbr;

	isneg = 0;
	nbr = 0;
	i = 0;
	if (!p || !*p)
		return (0);
	if (p[i] == '-')
		isneg = 1;
	if (p[i] == '+' || p[i] == '-')
		i++;
	while (p[i] && p[i] >= '0' && p[i] <= '9')
	{
		nbr = nbr * 10 + (p[i] - '0');
		i++;
	}
	if (p[i] == '.')
		nbr = get_div(i, p, nbr);
	if (isneg == 1)
		nbr = -nbr;
	return (nbr);
}
