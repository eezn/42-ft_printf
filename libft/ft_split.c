/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:02:56 by jin-lee           #+#    #+#             */
/*   Updated: 2021/01/24 17:24:00 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_chunk(const char *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void			ft_copy(char *cntnr, const char *start, const char *end)
{
	while (start < end)
	{
		*cntnr = *start;
		cntnr++;
		start++;
	}
	*cntnr = 0;
}

static char			**ft_free(char **cntnr, size_t cdx)
{
	size_t		idx;

	idx = 0;
	while (idx < cdx)
	{
		free(cntnr[idx]);
		idx++;
	}
	free(cntnr);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char		**cntnr;
	size_t		start;
	size_t		idx;
	size_t		cdx;

	if (!(cntnr = (char **)malloc(sizeof(char *) * (get_chunk(s, c) + 1))))
		return (0);
	idx = 0;
	cdx = 0;
	while (s[idx])
	{
		if (s[idx] != c)
		{
			start = idx;
			while (s[idx] && (s[idx] != c))
				idx++;
			if (!(cntnr[cdx] = (char *)malloc(idx - start + 1)))
				ft_free(cntnr, cdx);
			ft_copy(cntnr[cdx++], &s[start], &s[idx]);
		}
		else
			idx++;
	}
	cntnr[cdx] = 0;
	return (cntnr);
}
