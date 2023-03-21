/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:58:23 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/17 16:36:35 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define W_WID 1920
# define W_HET 1080
# define WMIDDLE 960
# define HMIDDLE 540

# define WHITE	0X00FFFFFF
# define BLACK	0x00000000
# define BLUE	0XFF0000FF

# define ESC	53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point {
	int	height;
	int	x;
	int	y;
	int	color;
}				t_point;

typedef struct s_map {
	char	**div;
	char	**port;
	int		width;
	int		height;
	int		step;
	t_point	**link;
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}				t_mlx;

typedef struct s_fdf {
	int		x_axis;
	int		y_axis;
	int		xrom;
	int		yrom;
}				t_fdf;

typedef struct s_bres {
	int		dx;
	int		dy;
	int		step_x;
	int		step_y;
	int		error;
	int		error_load;
	t_point	alt_out;
}				t_bres;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*file_protection(char *s);
void	map_reading(int fd, t_map *sizes);
int		ft_kill(char *reason);
void	posay_iso(t_map *try);
void	map_sweeping(char *s, t_map *fetch);
void	draw_map(t_map *final, t_data *full);
void	free_2d(char **str);
void	dimension_error(t_map *grp, int *i);
int		ft_color(char *str);
int		exit_window(void);
t_point	*collect_analytics(t_map *try, char *line);
t_bres	line_data(t_point *outset, t_point *dest);
void	ft_iso(t_map *map);
void	draw_line(t_data *img, t_point outset, t_point dest);
void	center_map(t_map *map);
void	step_decision(t_map *mok);
double	color_stat(int outset, int dest, int alt_point);
int		line_lit(t_point outset, t_point dest, t_point alt_point);
int		stop(int keycode, t_mlx *fdf);
int		get_light(int outset, int dest, double percentage);
#endif