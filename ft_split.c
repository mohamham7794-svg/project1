/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohhammo <mohhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:10:27 by mohhammo          #+#    #+#             */
/*   Updated: 2025/10/27 14:10:27 by mohhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_split(char **split, int i)
{
	while (i-- > 0)
		free(split[i]);
	free(split);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	fill_word(char **split, int i, const char **s, char c)
{
	int	len;

	while (**s == c)
		(*s)++;
	len = word_len(*s, c);
	split[i] = malloc(len + 1);
	if (!split[i])
		return (0);
	ft_strlcpy(split[i], *s, len + 1);
	*s += len;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		if (!fill_word(split, i, &s, c))
			return (free_split(split, i), NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}
