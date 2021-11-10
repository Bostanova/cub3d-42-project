/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:32:23 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 10:37:50 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	unsigned int	number;

	number = n;
	len = ft_numberlen(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!(s))
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = -n;
		s[0] = '-';
	}
	len--;
	while (number)
	{
		s[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return (s);
}
