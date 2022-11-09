/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:32:44 by amarques          #+#    #+#             */
/*   Updated: 2022/11/09 13:41:26 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static	void	exit_game2(t_mlx *data, int status)
{
	int	i;

	i = 0;
	if (data->img)
	{
		while (data->img[i])
			mlx_destroy_image(data->mlx, data->img[i++]);
		free(data->img);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit (status);
}

static int	exit_game(t_mlx	*data, int status)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	i = 0;
	if (data->tmp)
	{
		while (data->tmp[i])
			free(data->tmp[i++]);
		free(data->tmp);
	}
	exit_game2(data, status);
	return (1);
}

int	print_error(t_mlx *data, char *str, int status)
{
	if (status)
		ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit_game(data, status);
	return (0);
}
