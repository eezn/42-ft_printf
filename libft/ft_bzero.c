/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:37:52 by jin-lee           #+#    #+#             */
/*   Updated: 2020/12/29 22:52:30 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *dst, size_t len)
{
	unsigned char	*udst;

	udst = (unsigned char *)dst;
	while (len--)
		*udst++ = 0;
}
