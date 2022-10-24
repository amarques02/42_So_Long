/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:54:58 by amarques          #+#    #+#             */
/*   Updated: 2022/10/24 16:40:55 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void move(int x,int y, int keycode, t_mlx *data)
{
	if (data->map[(data->player_y /64) + (y /64)][(data->player_x / 64) + (x / 64)] == '1')
		return ;
	if (data->map[(data->player_y /64) + (y /64)][(data->player_x / 64) + (x / 64)] == 'E')
	{
		if (data->collectable == 0)
			exit_game(data);
		return ;
	}
	if (data->map[(data->player_y /64) + (y /64)][(data->player_x / 64) + (x / 64)] == 'C')
	{
		data->map[(data->player_y /64) + (y /64)][(data->player_x / 64) + (x / 64)] = '0';
		data->collectable--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0], data->player_x, data->player_y);
	data->player_x += x;
	data->player_y += y;
	mlx_put_image_to_window(data->mlx, data->win, data->img[(keycode == 100) * 2 + (keycode == 97) * 3 \
	+ (keycode == 119) * 4 + (keycode == 115) * 5], data->player_x, data->player_y);
}

int key(int keycode, void *param)
{
	t_mlx	*data;
	data = param;
	ft_printf("%d\n", keycode);
	int	x;
	int	y;
	
	if (keycode == 65307)
		exit_game(data);
	if (!(keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119))
		return (1);
	x = ((keycode == 100) - (keycode == 97)) * 64;
	y = ((keycode == 115) - (keycode == 119)) * 64;
	move(x, y, keycode, data);
	return (0);
}
