/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:38:04 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/16 18:51:43 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int	ft_kill(char *reason)
{
	ft_putendl(reason);
	return (1);
}

void	free_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	step_decision(t_map *mok)
{
	if (mok->width > mok->height)
		mok->step = (W_WID / mok->width) / 2;
	else
		mok->step = (W_HET / mok->height) / 2;
}

int	stop(int keycode, t_mlx *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		exit (0);
	}
	return (0);
}

int	exit_window(void)
{
	exit(0);
}