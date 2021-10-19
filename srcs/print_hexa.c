/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:50:03 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:59:32 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_hexa_value_len(t_fmt *fmt, int digit_len)
{
	int		value_len;

	if (fmt->precision > digit_len)
		value_len = fmt->precision;
	else
		value_len = digit_len;
	if (fmt->prefix)
		value_len += 2;
	if (fmt->zero && (fmt->width > value_len))
		value_len = fmt->width;
	return (value_len);
}

int		hexa_aligned_right(char *hexa, int h_len, t_fmt *fmt, unsigned int n)
{
	int		len;
	int		v_len;

	len = 0;
	v_len = check_hexa_value_len(fmt, h_len);
	if (fmt->zero == TRUE)
	{
		if (fmt->prefix && n)
			len += print_prefix(fmt->hexa);
		len += padding('0', fmt->width - h_len - len);
	}
	if (fmt->zero == FALSE)
	{
		len += padding(' ', fmt->width - v_len);
		if (fmt->prefix && n)
			len += print_prefix(fmt->hexa);
	}
	len += padding('0', fmt->precision - h_len);
	len += write(1, hexa, h_len);
	return (len);
}

int		hexa_aligned_left(char *hexa, int h_len, t_fmt *fmt, unsigned int n)
{
	int		len;

	len = 0;
	if (fmt->prefix && n)
		len += print_prefix(fmt->hexa);
	len += padding('0', fmt->precision - h_len);
	len += write(1, hexa, h_len);
	len += padding(' ', fmt->width - len);
	return (len);
}

int		print_hexa(va_list values, t_fmt *fmt)
{
	int					ret;
	unsigned long long	num;
	char				*hexa_str;
	int					hexa_len;

	ret = 0;
	num = va_arg(values, unsigned int);
	hexa_str = set_str_base(num, fmt->hexa);
	hexa_len = ft_strlen(hexa_str);
	if (fmt->precision != DEFAULT)
		fmt->zero = FALSE;
	if (fmt->precision != DEFAULT && num == 0)
		hexa_len = hexa_len - 1;
	if (fmt->align == RIGHT)
		ret = hexa_aligned_right(hexa_str, hexa_len, fmt, num);
	if (fmt->align == LEFT)
		ret = hexa_aligned_left(hexa_str, hexa_len, fmt, num);
	free(hexa_str);
	return (ret);
}
