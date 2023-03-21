/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:43:17 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/16 18:52:26 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= 0 && x < W_WID && y >= 0 && y < W_HET)
	{
		offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
		dst = data->addr + offset;
		*(unsigned int *)dst = color;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	gif;
	t_map	sweesh;
	int		fd;

	if (argc != 2)
		return (ft_kill("Error : not enough arguments !"));
	fd = open(argv[1], O_RDONLY);
	file_protection(argv[1]);
	map_reading(fd, &sweesh);
	gif.mlx = mlx_init();
	gif.mlx_win = mlx_new_window(gif.mlx, W_WID, W_HET, "FdF");
	gif.img.img = mlx_new_image(gif.mlx, W_WID, W_HET);
	gif.img.addr = mlx_get_data_addr(gif.img.img, &gif.img.bits_per_pixel,
			&gif.img.line_length, &gif.img.endian);
	ft_iso(&sweesh);
	center_map(&sweesh);
	draw_map(&sweesh, &gif.img);
	mlx_put_image_to_window(gif.mlx, gif.mlx_win, gif.img.img, 0, 0);
	mlx_key_hook(gif.mlx_win, stop, &gif);
	mlx_hook(gif.mlx_win, 17, 0, exit_window, &gif);
	mlx_loop(gif.mlx);
	return (0);
}
