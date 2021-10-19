/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:30:51 by jin-lee           #+#    #+#             */
/*   Updated: 2021/05/31 21:57:39 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fmt(t_fmt *fmt)
{
	fmt->align = RIGHT;
	fmt->zero = FALSE;
	fmt->sign = FALSE;
	fmt->width = FALSE;
	fmt->prefix = FALSE;
	fmt->precision = DEFAULT;
	fmt->is_negative = FALSE;
	fmt->hexa = DEFAULT;
}

int		padding(int c, int size)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (i++ < size)
		len += write(1, &c, 1);
	return (len);
}
