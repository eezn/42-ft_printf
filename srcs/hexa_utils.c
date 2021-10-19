/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 02:32:47 by jin-lee           #+#    #+#             */
/*   Updated: 2021/06/02 13:47:11 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		get_base_len(unsigned long long num, int base_size)
{
	size_t		len;

	len = 1;
	while (num /= base_size)
		len++;
	return (len);
}

char		*u_itoa_base(unsigned long long num, char *base, int base_size)
{
	char		*ret;
	size_t		len;
	size_t		idx;

	len = get_base_len(num, base_size);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (num == 0)
		ret[0] = '0';
	idx = len;
	ret[idx--] = '\0';
	while (num != 0)
	{
		ret[idx--] = base[num % base_size];
		num /= base_size;
	}
	return (ret);
}

char		*set_str_base(unsigned long long num, char type)
{
	char	*ret;

	if (type == 'x')
		ret = u_itoa_base(num, "0123456789abcdef", 16);
	if (type == 'X')
		ret = u_itoa_base(num, "0123456789ABCDEF", 16);
	return (ret);
}

int			print_prefix(char type)
{
	write(1, "0", 1);
	write(1, &type, 1);
	return (2);
}
