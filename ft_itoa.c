/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhammo <mohhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:57 by mohhammo          #+#    #+#             */
/*   Updated: 2025/11/15 20:56:31 by mohhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = (long)n;
	len = ft_numlen(num);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
