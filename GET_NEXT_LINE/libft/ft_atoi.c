/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:05:35 by jsanford          #+#    #+#             */
/*   Updated: 2018/11/30 17:06:51 by jsanford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(const char *str, long long res, int sign)
{
	long long	max;

	max = 922337203685477580;
	if ((res > max) || (res == max && *str > '7'))
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return (1);
}

int		ft_atoi(const char *str)
{
	long long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (ft_max(str, res, sign) != 1)
			return (ft_max(str, res, sign));
		res = res * 10 + *str++ - '0';
	}
	return (res * sign);
}
