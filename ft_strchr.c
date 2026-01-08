/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhammo <mohhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:10:46 by mohhammo          #+#    #+#             */
/*   Updated: 2025/10/27 14:10:46 by mohhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
