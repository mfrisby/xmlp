/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:28:42 by mfrisby           #+#    #+#             */
/*   Updated: 2017/07/12 14:11:38 by mfrisby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

typedef struct		s_env
{
	FILE			*file;
	char			*str;
	int				family;
	int				fd;
	char			result[4000];
	size_t			size;
	size_t			index;
	int				i;
	char			type;
	int				nb_arg;
	int				flag_plus;
	int				flag_diese;
	int				flag_moins;
	int				flag_space;
	int				flag_zero;
	int				precision;
	int				field_width;
	int				neg;
	int				m_h;
	int				m_hh;
	int				m_l;
	int				m_ll;
	int				m_j;
	int				m_z;
	va_list			pa;
}					t_env;

void				ft_printf_b(t_env *e);
char				*ft_stoa_base(long long nb, int base);
char				*ft_utoa_base(unsigned long long nb, int base);
void				ft_printf_parser(t_env *e, char *format);
int					ft_printf_precision(t_env *e, char *format);
int					ft_printf_length(t_env *e, char *format);
size_t				ft_printf_unicode(unsigned char *const buffer,
		const unsigned int code);
int					ft_printf_conversion(t_env *e, char c);
void				ft_printf_s(t_env *e);
void				ft_printf_smaj(t_env *e);
void				ft_printf_p(t_env *e);
void				ft_printf_di(t_env *e);
void				ft_printf_dmaj(t_env *e);
void				ft_printf_omaj(t_env *e);
void				ft_printf_o(t_env *e);
void				ft_printf_u(t_env *e);
void				ft_printf_umaj(t_env *e);
void				ft_printf_x(t_env *e);
void				ft_printf_xmaj(t_env *e);
void				ft_printf_c(t_env *e);
void				ft_printf_cmaj(t_env *e);
void				ft_printf_modulo(t_env *e);
void				ft_printf_add_to_buffer(t_env *e, char *s, int start);
void				ft_printf_buffer_flush(t_env *e);
char				*remove_min(t_env *e, char *tmp);
void				ft_printf_putflags(t_env *e, char *s);
char				*getspace(t_env *e, char *space, char *s);

#endif
