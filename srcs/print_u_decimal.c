/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:10:14 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:56:49 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_u_value_len(t_fmt *fmt, int digit_len)
{
	int		value_len;

	if (fmt->precision > digit_len)
		value_len = fmt->precision;
	else
		value_len = digit_len;
	if (fmt->zero && (fmt->width > value_len))
		value_len = fmt->width;
	return (value_len);
}

int		u_aligned_right(char *d_str, int d_len, int v_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	if (fmt->zero == TRUE)
		len += padding('0', fmt->width - d_len);
	if (fmt->zero == FALSE)
		len += padding(' ', fmt->width - v_len);
	len += padding('0', fmt->precision - d_len);
	len += write(1, d_str, d_len);
	return (len);
}

int		u_aligned_left(char *d_str, int d_len, int v_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	len += padding('0', fmt->precision - d_len);
	len += write(1, d_str, d_len);
	len += padding(' ', fmt->width - v_len);
	return (len);
}

int		print_u_decimal(va_list values, t_fmt *fmt)
{
	int					ret;
	unsigned long long	num;
	char				*digit_str;
	int					digit_len;
	int					value_len;

	num = va_arg(values, unsigned int);
	digit_str = u_itoa_base(num, "0123456789", 10);
	digit_len = ft_strlen(digit_str);
	if (fmt->precision != DEFAULT)
		fmt->zero = FALSE;
	if (fmt->precision != DEFAULT && num == 0)
		digit_len = digit_len - 1;
	value_len = check_u_value_len(fmt, digit_len);
	if (fmt->align == RIGHT)
		ret = u_aligned_right(digit_str, digit_len, value_len, fmt);
	if (fmt->align == LEFT)
		ret = u_aligned_left(digit_str, digit_len, value_len, fmt);
	free(digit_str);
	return (ret);
}
