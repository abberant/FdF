/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:27:20 by aanouari          #+#    #+#             */
/*   Updated: 2023/02/15 16:28:45 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "libft.h"

void	ft_putstr(char *str)
{
	if (!str)
		ft_putstr("(null)");
	while (*str)
		ft_putchar(*(str++));
	ft_putchar('\n');
}
