/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhammo <mohhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:04:21 by mohhammo          #+#    #+#             */
/*   Updated: 2025/10/27 14:04:21 by mohhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dest);
}
