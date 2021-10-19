/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:17:56 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:50:27 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define RIGHT 0
# define LEFT 1

# define DEFAULT -1
# define ONLY_DOT 0
# define CHAR -1
# define PERCENT '%'

typedef struct	s_fmt
{
	int		align;
	int		zero;
	int		sign;
	int		width;
	int		prefix;
	int		precision;
	int		is_negative;
	int		hexa;
}				t_fmt;

void			init_fmt(t_fmt *fmt);
void			fmt_parser(const char **format, va_list values, t_fmt *fmt);
void			set_align_left(t_fmt *fmt);
void			check_sign(const char **format, t_fmt *fmt);
void			check_width(va_list valuse, t_fmt *fmt);
void			check_precision(\
				const char **format, va_list values, t_fmt *fmt);
int				u_atoi(const char **format);

char			*u_itoa_base(\
				unsigned long long num, char *base, int base_size);
char			*set_str_base(unsigned long long num, char type);

int				padding(int c, int size);
int				print_prefix(char type);
int				print_char(va_list values, t_fmt *fmt, int character);
int				print_string(va_list values, t_fmt *fmt);
int				print_decimal(va_list values, t_fmt *fmt);
int				print_u_decimal(va_list values, t_fmt *fmt);
int				print_hexa(va_list values, t_fmt *fmt);
int				print_address(va_list values, t_fmt *fmt);

int				mixing_bowl(const char **type, va_list values, t_fmt *fmt);
int				formatted(const char **format, va_list values);
int				non_formatted(const char **format);
int				ft_printf(const char *format, ...);

#endif
