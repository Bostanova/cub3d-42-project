/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:31:52 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 11:46:02 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

size_t	ft_wordslen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**frees(char **res, size_t col_nw)
{
	size_t	j;

	j = 0;
	while (j < col_nw)
	{
		free((char *)res[j]);
		j++;
	}
	free(res);
	res = NULL;
	return (NULL);
}

size_t	count_help(char const *s, char c, size_t i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc((words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < words(s, c))
	{
		i = count_help(s, c, i);
		res[j] = ft_substr(s, i, ft_wordslen(&(s[i]), c));
		if (!res[j])
		{
			frees(res, j);
			return (NULL);
		}
		i += ft_wordslen(&(s[i]), c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
