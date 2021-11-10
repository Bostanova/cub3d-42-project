/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:01:06 by eerika            #+#    #+#             */
/*   Updated: 2021/05/12 10:33:49 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	ft_atoi_helper(int len, int sign, int number)
{
	int	i;

	if (len > 18)
	{
		if (sign == -1)
			i = 0;
		if (sign == 1)
			i = -1;
	}
	else
		i = number * sign;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	len;
	int	sign;

	number = 0;
	len = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		number = number * 10 + (*str - 48);
		str++;
		len++;
	}
	return (ft_atoi_helper(len, sign, number));
}
