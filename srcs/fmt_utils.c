/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:28:23 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 01:09:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_align_left(t_fmt *fmt)
{
	fmt->align = LEFT;
	fmt->zero = FALSE;
}

void	check_sign(const char **format, t_fmt *fmt)
{
	if (fmt->sign == ' ')
		fmt->sign = ' ';
	else
		fmt->sign = **format;
}

int		u_atoi(const char **format)
{
	int		num;

	num = 0;
	while (ft_isdigit(**format))
	{
		num *= 10;
		num += (int)(*(*format)++) - '0';
	}
	(*format)--;
	return (num);
}

void	check_width(va_list values, t_fmt *fmt)
{
	if ((fmt->width = va_arg(values, int)) < 0)
	{
		fmt->width *= (-1);
		set_align_left(fmt);
	}
}

void	check_precision(const char **format, va_list values, t_fmt *fmt)
{
	if (ft_isdigit(*(++(*format))))
		fmt->precision = u_atoi(format);
	else if (**format == '*')
	{
		if ((fmt->precision = va_arg(values, int)) < 0)
			fmt->precision = DEFAULT;
	}
	else
	{
		fmt->precision = ONLY_DOT;
		(*format)--;
	}
}
