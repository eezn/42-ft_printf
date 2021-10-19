/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:18:28 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:58:13 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_addr_value_len(t_fmt *fmt, int digit_len)
{
	int		value_len;

	if (fmt->precision > 2 + digit_len)
		value_len = fmt->precision;
	else
		value_len = 2 + digit_len;
	if (fmt->zero && (fmt->width > value_len))
		value_len = fmt->width;
	return (value_len);
}

int		addr_aligned_right(char *addr, int addr_len, int value_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	if (fmt->zero == TRUE)
	{
		len += write(1, "0x", 2);
		len += padding('0', fmt->width - addr_len);
	}
	if (fmt->zero == FALSE)
	{
		len += padding(' ', fmt->width - value_len);
		len += write(1, "0x", 2);
	}
	len += padding('0', fmt->precision - addr_len);
	len += write(1, addr, addr_len);
	return (len);
}

int		addr_aligned_left(char *addr, int addr_len, int value_len, t_fmt *fmt)
{
	int		len;

	len = 0;
	len += write(1, "0x", 2);
	len += padding('0', fmt->precision - addr_len);
	len += write(1, addr, addr_len);
	len += padding(' ', fmt->width - value_len);
	return (len);
}

int		print_address(va_list values, t_fmt *fmt)
{
	int					ret;
	unsigned long long	addr;
	char				*addr_str;
	int					addr_len;
	int					value_len;

	ret = 0;
	addr = (unsigned long long)va_arg(values, void *);
	addr_str = set_str_base(addr, 'x');
	addr_len = ft_strlen(addr_str);
	if (fmt->precision != DEFAULT)
		fmt->zero = FALSE;
	if (fmt->precision != DEFAULT && addr == 0)
		addr_len = addr_len - 1;
	value_len = check_addr_value_len(fmt, addr_len);
	if (fmt->align == RIGHT)
		ret += addr_aligned_right(addr_str, addr_len, value_len, fmt);
	if (fmt->align == LEFT)
		ret += addr_aligned_left(addr_str, addr_len, value_len, fmt);
	free(addr_str);
	return (ret);
}
