/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:39 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 10:28:58 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*str;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		res[i] = str[i];
		if (res[i] == (unsigned char)c)
			return ((void *)(res + i + 1));
		i++;
	}
	return (NULL);
}
