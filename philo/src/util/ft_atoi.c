/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:31:08 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/26 21:02:27 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosoper.h"

int	ft_atoi(const char *str)
{
	int			neg;
	long long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (neg < 0 && neg * num > 0)
		return (0);
	else if (neg > 0 && neg * num < 0)
		return (-1);
	return (neg * num);
}
