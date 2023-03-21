/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:01:23 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/16 18:44:42 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

char	*file_protection(char *s)
{
	if (!s)
		return (NULL);
	if (!(ft_strnstr(s, ".fdf", ft_strlen(s))))
	{
		ft_putstr_fd("Error, Invalid File !", 2);
		exit(1);
	}
	return (NULL);
}


t_point	*collect_analytics(t_map *try, char *line)
{
	static int	y_axe;
	t_point		*info;
	int			i;

	i = 0;
	try->div = ft_split(line, ' ');
	while (try->div[i])
		i++;
	try->width = i;
	info = malloc(try->width * sizeof(t_point));
	if (!info)
		return (NULL);
	i = 0;
	step_decision(try);
	while (try->div[i])
	{
		info[i].x = i * try->step;
		info[i].y = y_axe * try->step;
		info[i].height = ft_atoi(try->div[i]);
		info[i].color = ft_color(try->div[i]);
		i++;
	}
	free_2d(try->div);
	y_axe++;
	return (info);
}

void	map_sweeping(char *s, t_map *fetch)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("FDF file is empty !", 2);
		exit (1);
	}
	fetch->width = 0;
	fetch->port = ft_split(s, '\n');
	fetch->link = ft_calloc(fetch->height, sizeof(t_point **));
	if (!fetch->link)
		return ;
	while (fetch->port[i])
	{
		fetch->link[i] = collect_analytics(fetch, fetch->port[i]);
		i++;
	}
	free_2d(fetch->port);
	ft_putstr("Success !");
}

void	map_reading(int fd, t_map *sizes)
{
	char	*read;
	char	*stash;

	stash = NULL;
	sizes->height = 0;
	while (1)
	{
		read = get_next_line(fd);
		if (read == NULL)
			break ;
		stash = ft_strjoin(stash, read);
		sizes->height++;
		free (read);
	}
	map_sweeping(stash, sizes);
	free(stash);
}