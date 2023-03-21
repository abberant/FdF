/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:10:41 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:43:17 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == 32 || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		else if (num > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (num * sign);
}
