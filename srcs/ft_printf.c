/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:35:27 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 01:29:33 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fmt_parser(const char **format, va_list values, t_fmt *fmt)
{
	while (*(++(*format)))
	{
		if (**format == '0' && fmt->align == RIGHT)
			fmt->zero = TRUE;
		else if (**format == '-')
			set_align_left(fmt);
		else if (**format == ' ' || **format == '+')
			check_sign(format, fmt);
		else if (**format == '#')
			fmt->prefix = TRUE;
		else if (ft_isdigit(**format))
			fmt->width = u_atoi(format);
		else if (**format == '*')
			check_width(values, fmt);
		else if (**format == '.')
			check_precision(format, values, fmt);
		else
			break ;
	}
}

int		mixing_bowl(const char **type, va_list values, t_fmt *fmt)
{
	int			len;

	len = 0;
	if (**type == '%')
		len = print_char(values, fmt, PERCENT);
	else if (**type == 'c')
		len = print_char(values, fmt, CHAR);
	else if (**type == 's')
		len = print_string(values, fmt);
	else if (**type == 'd' || **type == 'i')
		len = print_decimal(values, fmt);
	else if (**type == 'u')
		len = print_u_decimal(values, fmt);
	else if (**type == 'p')
		len = print_address(values, fmt);
	else if (**type == 'x' || **type == 'X')
	{
		fmt->hexa = **type;
		len = print_hexa(values, fmt);
	}
	else
		(*type)--;
	return (len);
}

int		formatted(const char **format, va_list values)
{
	t_fmt		fmt;
	int			len;

	len = 0;
	init_fmt(&fmt);
	fmt_parser(format, values, &fmt);
	len = mixing_bowl(format, values, &fmt);
	return (len);
}

int		non_formatted(const char **format)
{
	const char	*str;
	int			str_len;

	str_len = 0;
	str = *format;
	while (**format && **format != '%')
	{
		str_len++;
		(*format)++;
	}
	(*format)--;
	return (write(1, str, str_len));
}

int		ft_printf(const char *format, ...)
{
	va_list		values;
	int			total_len;

	total_len = 0;
	va_start(values, format);
	while (*format)
	{
		if (*format == '%')
			total_len += formatted(&format, values);
		else
			total_len += non_formatted(&format);
		format++;
	}
	va_end(values);
	return (total_len);
}
