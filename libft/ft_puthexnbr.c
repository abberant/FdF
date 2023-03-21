/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:29:12 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/12 04:23:17 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fdf.h"

void	ft_puthexnbr(unsigned long n, int upper)
{
	char	c;

	c = 0;
	if (n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = n + (97 - (32 * upper)) - 10;
		ft_putchar(c);
	}
	else
	{
		ft_puthexnbr(n / 16, upper);
		ft_puthexnbr(n % 16, upper);
	}
}
