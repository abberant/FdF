/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:16:09 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/16 00:39:36 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	center_map(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	x = WMIDDLE - map->link[map->height / 2][map->width / 2].x;
	y = HMIDDLE - map->link[map->height / 2][map->width / 2].y;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->link[i][j].x = (map->link[i][j].x) + x;
			map->link[i][j].y = (map->link[i][j].y) + y;
		}
	}
}

void	ft_iso(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->link[i][j].x = (map->link[i][j].x - map->link[i][j].y)
				* cos(0.7);
			map->link[i][j].y = (map->link[i][j].x + map->link[i][j].y)
				* sin(0.7) - map->link[i][j].height;
		}
	}
}

void	draw_map(t_map *final, t_data *full)
{
	int		j;
	int		i;

	i = 0;
	while (i < final->height)
	{
		j = 0;
		while (j < final->width)
		{
			if (j < final->width - 1)
				draw_line(full, final->link[i][j], final->link[i][j + 1]);
			if (i < final->height - 1)
				draw_line(full, final->link[i][j], final->link[i + 1][j]);
			j++;
		}
		i++;
	}
}

t_bres	line_data(t_point *outset, t_point *dest)
{
	t_bres	hold;

	hold.dx = abs(dest->x - outset->x);
	hold.dy = -abs(dest->y - outset->y);
	hold.step_x = 1;
	hold.step_y = 1;
	hold.error = hold.dx + hold.dy;
	if (outset->x > dest->x)
		hold.step_x = -1;
	if (outset->y > dest->y)
		hold.step_y = -1;
	hold.alt_out = *outset;
	return (hold);
}

void	draw_line(t_data *img, t_point outset, t_point dest)
{
	t_bres	set;
	int		color;

	set = line_data(&outset, &dest);
	while (1)
	{
		color = line_lit(outset, dest, set.alt_out);
		my_mlx_pixel_put(img, set.alt_out.x, set.alt_out.y, color);
		set.error_load = set.error * 2;
		if (set.error_load >= set.dy)
		{
			if (set.alt_out.x == dest.x)
				break ;
			set.error += set.dy;
			set.alt_out.x += set.step_x;
		}
		if (set.error_load <= set.dx)
		{
			if (set.alt_out.y == dest.y)
				break ;
			set.error += set.dx;
			set.alt_out.y += set.step_y;
		}
	}
}
