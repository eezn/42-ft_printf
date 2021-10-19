/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:03:47 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:53:36 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_value_len(t_fmt *fmt, int digit_len)
{
	int		value_len;

	if (fmt->precision > digit_len)
		value_len = fmt->precision;
	else
		value_len = digit_len;
	if (fmt->is_negative == TRUE || fmt->sign != FALSE)
		value_len += 1;
	if (fmt->zero && (fmt->width > value_len))
		value_len = fmt->width;
	return (value_len);
}

int		print_sign(t_fmt *fmt)
{
	char	sign;

	if (fmt->is_negative == TRUE)
		return (write(1, "-", 1));
	else if ((sign = fmt->sign) != FALSE)
		return (write(1, &sign, 1));
	return (0);
}

int		aligned_right(char *digit_str, int digit_len, int value_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	if (fmt->zero == TRUE)
	{
		len += print_sign(fmt);
		len += padding('0', fmt->width - digit_len - len);
	}
	if (fmt->zero == FALSE)
	{
		len += padding(' ', fmt->width - value_len);
		len += print_sign(fmt);
	}
	len += padding('0', fmt->precision - digit_len);
	len += write(1, digit_str, digit_len);
	return (len);
}

int		aligned_left(char *digit_str, int digit_len, int value_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	len += print_sign(fmt);
	len += padding('0', fmt->precision - digit_len);
	len += write(1, digit_str, digit_len);
	len += padding(' ', fmt->width - value_len);
	return (len);
}

int		print_decimal(va_list values, t_fmt *fmt)
{
	int			ret;
	long long	num;
	char		*digit_str;
	int			digit_len;
	int			value_len;

	num = va_arg(values, int);
	if (num < 0)
	{
		num *= (-1);
		fmt->is_negative = TRUE;
	}
	digit_str = ft_itoa(num);
	digit_len = ft_strlen(digit_str);
	if (fmt->precision != DEFAULT)
		fmt->zero = FALSE;
	if (fmt->precision != DEFAULT && num == 0)
		digit_len = digit_len - 1;
	value_len = check_value_len(fmt, digit_len);
	if (fmt->align == RIGHT)
		ret = aligned_right(digit_str, digit_len, value_len, fmt);
	if (fmt->align == LEFT)
		ret = aligned_left(digit_str, digit_len, value_len, fmt);
	free(digit_str);
	return (ret);
}
