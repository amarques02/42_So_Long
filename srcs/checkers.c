/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:37:27 by amarques          #+#    #+#             */
/*   Updated: 2022/11/07 15:24:34 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	invalid_char(t_mlx *data, int j, int i)
{
	if (data->map[j][i] != 'P' && data->map[j][i] != 'E' && \
		data->map[j][i] != 'C' && data->map[j][i] != '1' && \
		data->map[j][i] != '0' && data->map[j][i] != 'X' && \
		data->map[j][i] != '\n')
		return (0);
	return (1);
}

int	chr_counter(t_mlx *data, int j, int i)
{
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				data->e_count++;
			if (data->map[j][i] == 'C')
				data->c_count++;
			if (data->map[j][i] == 'P')
			{
				data->player_x = i * 64;
				data->player_y = j * 64;
				data->p_count++;
			}
			if (!invalid_char(data, j, i))
				return (0);
			i++;
		}
		j++;
	}
	if (data->e_count != 1 || data->p_count != 1 || data->c_count < 1)
		return (0);
	return (1);
}

int	format_check(t_mlx *data, int i, int j)
{
	data->l = map_length(data->map);
	data->h = map_height(data->map);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'E')
			{
				data->exit_x = i;
				data->exit_y = j;
			}
			i++;
		}
		if (i != data->l)
			return (0);
		j++;
	}
	return (1);
}

int	border_check(t_mlx *data, int i)
{
	while (i < data->l)
	{
		if (data->map[0][i] != '1' || data->map[data-> h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < data->h - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->l - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	path_checker(char **map, int y, int x)
{
	if (map[y + 1][x] && (map[y + 1][x] == 'C' || map[y + 1][x] == '0'))
	{
		map[y + 1][x] = 'P';
		path_checker(map, y + 1, x);
	}
	if (map[y - 1][x] && (map[y - 1][x] == 'C' || map[y - 1][x] == '0'))
	{
		map[y - 1][x] = 'P';
		path_checker(map, y - 1, x);
	}
	if (map[y][x + 1] && (map[y][x + 1] == 'C' || map[y][x + 1] == '0'))
	{
		map[y][x + 1] = 'P';
		path_checker(map, y, x + 1);
	}
	if (map[y][x - 1] && (map[y][x - 1] == 'C' || map[y][x - 1] == '0'))
	{
		map[y][x - 1] = 'P';
		path_checker(map, y, x - 1);
	}
}
