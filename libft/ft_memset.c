/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:23:02 by jin-lee           #+#    #+#             */
/*   Updated: 2020/12/29 22:52:41 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*udst;

	udst = (unsigned char *)dst;
	while (len--)
		*udst++ = (unsigned char)c;
	return (dst);
}
