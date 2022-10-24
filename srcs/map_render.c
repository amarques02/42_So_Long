/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:12:38 by amarques          #+#    #+#             */
/*   Updated: 2022/10/24 16:38:28 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


static void load_img(t_mlx *data, int i)
{
	data->img = malloc(9 * sizeof(void *));
	if (!data->img)
		return ;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm", &i, &i);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &i, &i);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "assets/playerright.xpm", &i, &i);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "assets/playerleft.xpm", &i, &i);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "assets/playerup.xpm", &i, &i);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "assets/playerdown.xpm", &i, &i);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "assets/exit2.xpm", &i, &i);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, "assets/capy2.xpm", &i, &i);
	data->img[8] = NULL;
}

void render(t_mlx *data)
{
	int	i;
	int	j;
	
	j = 0;
	load_img(data, 64);
	while(data->map[j])
	{
		i = 0;
		while(data->map[j][i])
		{
			if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img[1], (i * 64), (j * 64));
			else if (data->map[j][i] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img[0], (i * 64), (j * 64));
			else if (data->map[j][i] == 'P')
			{
				data->player_x = i * 64;
				data->player_y = j * 64;
				mlx_put_image_to_window(data->mlx, data->win, data->img[5], (i * 64), (j * 64));
			}
			else if (data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img[6], (i * 64), (j * 64));
			else if (data->map[j][i] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img[7], (i * 64), (j * 64));
				data->collectable++;
			}
			i++;
		}
		j++;
	}
}