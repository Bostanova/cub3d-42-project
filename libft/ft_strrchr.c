/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:49:18 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 10:26:03 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = c;
	i = ft_strlen(s);
	if (cc == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == cc)
			return ((char *)s + i);
	}
	return (NULL);
}
