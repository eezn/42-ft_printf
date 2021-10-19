/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:21:36 by jin-lee           #+#    #+#             */
/*   Updated: 2021/05/28 23:53:26 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_abs(long long n)
{
	unsigned long long		un;

	if (n < 0)
		un = n * (-1);
	else
		un = n;
	return (un);
}

static int					get_len(unsigned long long n)
{
	int			len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int					is_negative(long long n)
{
	int				sign;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

char						*ft_itoa(long long n)
{
	char				*ret;
	unsigned long long	un;
	int					sign;
	int					len;
	int					idx;

	sign = is_negative(n);
	un = ft_abs(n);
	len = sign + get_len(un);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (un == 0)
		ret[0] = '0';
	if (sign == 1)
		ret[0] = '-';
	idx = len;
	ret[idx--] = '\0';
	while (un != 0)
	{
		ret[idx--] = un % 10 + '0';
		un /= 10;
	}
	return (ret);
}
