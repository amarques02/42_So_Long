/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:28:37 by amarques          #+#    #+#             */
/*   Updated: 2022/11/07 16:25:03 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_img(t_mlx *data, int i)
{
	data->img = malloc(23 * sizeof(void *));
	if (!data->img)
		return ;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, \
	"assets/floor.xpm", &i, &i);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, \
	"assets/wall.xpm", &i, &i);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, \
	"assets/playerright.xpm", &i, &i);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, \
	"assets/playerleft.xpm", &i, &i);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, \
	"assets/playerup.xpm", &i, &i);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, \
	"assets/playerdown.xpm", &i, &i);
	load_img2(data, i);
}

void	load_img2(t_mlx *data, int i)
{
	data->img[6] = mlx_xpm_file_to_image(data->mlx, \
	"assets/exit.xpm", &i, &i);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy1.xpm", &i, &i);
	data->img[8] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy1.xpm", &i, &i);
	data->img[9] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy1.xpm", &i, &i);
	data->img[10] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy1.xpm", &i, &i);
	data->img[11] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy2.xpm", &i, &i);
	data->img[12] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy3.xpm", &i, &i);
	data->img[13] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capy4.xpm", &i, &i);
	data->img[14] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy1.xpm", &i, &i);
	load_img3(data, i);
}

void	load_img3(t_mlx *data, int i)
{
	data->img[15] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy1.xpm", &i, &i);
	data->img[16] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy1.xpm", &i, &i);
	data->img[17] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy1.xpm", &i, &i);
	data->img[18] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy2.xpm", &i, &i);
	data->img[19] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy3.xpm", &i, &i);
	data->img[20] = mlx_xpm_file_to_image(data->mlx, \
	"assets/capyenemy4.xpm", &i, &i);
	data->img[21] = mlx_xpm_file_to_image(data->mlx, \
	"assets/counter.xpm", &i, &i);
	data->img[22] = NULL;
}
