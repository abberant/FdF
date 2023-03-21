/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:20:32 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/17 16:57:05 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int	ft_color(char *str)
{
	char	**pt;
	int		color;
	int		i;

	i = 0;
	if (!ft_strchr(str, ','))
		return (BLUE);
	pt = ft_split(str, ',');
	color = ft_hex(pt[1] + 2);
	free_2d(pt);
	return (color);
}

double	color_stat(int outset, int dest, int alt_point)
{
	double	placement;
	double	distance;

	placement = alt_point - outset;
	distance = dest - outset;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_light(int outset, int dest, double percentage)
{
	return ((int)((1 - percentage) * outset + percentage * dest));
}

int	line_lit(t_point outset, t_point dest, t_point alt_point)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (outset.color == dest.color)
		return (alt_point.color);
	if (abs(dest.x - outset.x) > abs(dest.y - outset.y))
		percentage = color_stat(outset.x, dest.x, alt_point.x);
	else
		percentage = color_stat(outset.y, dest.y, alt_point.y);
	red = get_light((outset.color >> 16) & 0xFF,
			(dest.color >> 16) & 0xFF, percentage);
	green = get_light((outset.color >> 8) & 0xFF,
			(dest.color >> 8) & 0xFF, percentage);
	blue = get_light(outset.color & 0xFF,
			dest.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
