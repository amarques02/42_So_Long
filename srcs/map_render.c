/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:12:38 by amarques          #+#    #+#             */
/*   Updated: 2022/11/07 14:12:48 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	animation_render(t_mlx *data)
{
	int	j;
	int	i;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->animation, \
				(i * 64), (j * 64));
			if (data->map[j][i] == 'X')
				mlx_put_image_to_window(data->mlx, data->win, data->animation_e \
				, (i * 64), (j * 64));
			i++;
		}
		j++;
	}
}

int	animation(void *param)
{
	static int	count;
	static int	i = 7;
	static int	i_e = 14;
	static int	swap = 1;
	t_mlx		*data;

	data = param;
	if (count == 15000)
	{
		data->animation = data->img[i];
		data->animation_e = data->img[i_e];
		animation_render(data);
		i += swap;
		i_e += swap;
		if (i == 7 || i == 13)
			swap *= -1;
		count = 0;
	}
	else
		count++;
	return (0);
}

void	render(t_mlx *data)
{
	int	i;
	int	j;

	j = -1;
	load_img(data, 64);
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
			{
				data->player_x = i * 64;
				data->player_y = j * 64;
			}
			if (data->map[j][i] == 'C')
				data->collectable++;
			mlx_put_image_to_window(data->mlx, data->win, \
			data->img[(data->map[j][i] == 'P') * 5 + \
			(data->map[j][i] == '0') * 0 + (data->map[j][i] == 'C') * 7 \
			+ (data->map[j][i] == 'E') * 6 + (data->map[j][i] == 'X') * \
			14 + (data->map[j][i] == '1') * 1] \
			, i * 64, j * 64);
		}
	}
}
