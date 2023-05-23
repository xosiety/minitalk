/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:18:23 by afabbri           #+#    #+#             */
/*   Updated: 2023/02/12 00:08:29 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s && *s != c && ++i)
				++s;
			arr[j++] = ft_substr(s - i, 0, i);
		}
		else
			++s;
	}
	arr[j] = NULL;
	return (arr);
}
