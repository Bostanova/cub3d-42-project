/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:49:29 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 10:04:36 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	res = (char *)malloc(sizeof(*res) \
	* (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (res == 0)
		return (NULL);
	while (str1 != NULL && *str1 != '\0')
	{
		res[i] = *str1;
		i++;
		str1++;
	}
	while (str2 != NULL && *str2 != '\0')
	{
		res[i] = *str2;
		i++;
		str2++;
	}
	res[i] = '\0';
	return (res);
}
