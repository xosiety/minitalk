/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:36:45 by afabbri           #+#    #+#             */
/*   Updated: 2023/02/10 15:04:37 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*f;
	size_t			i;

	f = (unsigned char *)str;
	i = 0;
	while (i < n)
		f[i++] = c;
	return (str);
}
