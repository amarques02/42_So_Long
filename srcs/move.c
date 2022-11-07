/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:54:58 by amarques          #+#    #+#             */
/*   Updated: 2022/11/07 16:27:45 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	move(int x, int y, int keycode, t_mlx *data)
{
	char		*str;
	static int	steps;
	int			i;

	mlx_put_image_to_window(data->mlx, data->win, data->img[0], \
	data->player_x, data->player_y);
	data->player_x = x * 64;
	data->player_y = y * 64;
	mlx_put_image_to_window(data->mlx, data->win, data->img[\
	(keycode == 100) * 2 + (keycode == 97) * 3 + (keycode == 119) * 4 + \
	(keycode == 115) * 5], data->player_x, data->player_y);
	steps++;
	str = ft_itoa(steps);
	i = -1;
	while (++i < data->l)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[21], \
		i * 64, data->h * 64);
	}
	mlx_string_put(data->mlx, data->win, 32, \
	(map_height(data->map) * 64) + 32, 0xFFFFFF, str);
	free(str);
}

static int	check_move(t_mlx *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'E')
	{
		if (data->collectable == 0)
			print_error(data, "You secured all the capys B-)", 0);
		return (0);
	}
	if (data->map[y][x] == 'C')
	{
		data->collectable--;
		data->map[y][x] = '0';
	}
	if (data->map[y][x] == 'X')
		print_error(data, "Watch out! That capy didn\'t look too happy!", 0);
	return (1);
}

int	key(int keycode, void *param, t_mlx *data)
{
	int		x;
	int		y;

	data = param;
	if (keycode == 65307)
		print_error(data, "Game Closed", 0);
	if (!(keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119))
		return (1);
	x = data->player_x / 64 + ((keycode == 100) - (keycode == 97));
	y = data->player_y / 64 + ((keycode == 115) - (keycode == 119));
	if (check_move(data, x, y))
		move(x, y, keycode, data);
	return (0);
}
