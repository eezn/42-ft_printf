/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_series.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:46:15 by jin-lee           #+#    #+#             */
/*   Updated: 2021/05/27 22:51:24 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list values, t_fmt *fmt, int character)
{
	char	c;
	int		len;

	len = 0;
	if (character == CHAR)
		c = va_arg(values, int);
	else
		c = character;
	if (fmt->align == RIGHT)
	{
		if (fmt->zero == TRUE)
			len += padding('0', fmt->width - 1);
		if (fmt->zero == FALSE)
			len += padding(' ', fmt->width - 1);
	}
	len += write(1, &c, 1);
	if (fmt->align == LEFT)
		len += padding(' ', fmt->width - 1);
	return (len);
}

int		print_string(va_list values, t_fmt *fmt)
{
	char	*str;
	int		str_len;
	int		len;

	len = 0;
	str = va_arg(values, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (fmt->precision != DEFAULT)
		if (fmt->precision < str_len)
			str_len = fmt->precision;
	if (fmt->align == RIGHT)
	{
		if (fmt->zero == TRUE)
			len += padding('0', fmt->width - str_len);
		if (fmt->zero == FALSE)
			len += padding(' ', fmt->width - str_len);
	}
	len += write(1, str, str_len);
	if (fmt->align == LEFT)
		len += padding(' ', fmt->width - str_len);
	return (len);
}
