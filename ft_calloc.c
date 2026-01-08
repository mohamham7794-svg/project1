/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhammo <mohhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:46:26 by mohhammo          #+#    #+#             */
/*   Updated: 2025/11/15 17:34:20 by mohhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(size_t count, size_t size)
{
	if (count != 0 && size >= SIZE_MAX / count)
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (is_overflow(count, size))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
