/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:09:32 by afabbri           #+#    #+#             */
/*   Updated: 2023/02/11 20:37:08 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = (n / 10);
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	p;
	char		*str;
	int			len;
	int			i;

	i = -1;
	p = (long int)n;
	len = ft_intlen(p);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		p = p * -1;
		str[0] = '-';
		i = 0;
	}
	while (len > i)
	{
		((char *)str)[len--] = (p % 10) + 48;
		p = p / 10;
	}
	return (str);
}
