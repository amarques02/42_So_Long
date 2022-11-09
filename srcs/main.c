/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:13:04 by amarques          #+#    #+#             */
/*   Updated: 2022/11/09 13:52:17 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	exit_prog(t_mlx *data)
{
	print_error(data, "Game Closed", 0);
	return (0);
}

int	ber_checker(char **av)
{
	char	*dot;

	dot = ft_strrchr(av[1], '.');
	if (dot && !ft_strncmp(dot, ".ber", 5))
		return (1);
	return (0);
}

static void	validater(t_mlx *data, int j, int i)
{
	if (!chr_counter(data, 0, 0))
		print_error(data, "Invalid map", 1);
	if (!format_check(data, 0, 0))
		print_error(data, "Map is not a Rectangle", 1);
	if (!border_check(data, 0))
		print_error(data, "Map is not surrounded by walls", 1);
	map_cpy(data, 0, 0);
	path_checker(data->tmp, data->player_y / 64, data->player_x / 64);
	while (data->tmp[j])
	{
		i = 0;
		while (data->tmp[j][i])
		{
			if (data->tmp[j][i] == 'C')
				print_error(data, "Path is not valid", 1);
			i++;
		}
		j++;
	}
	if (!(data->tmp[data->exit_y + 1][data->exit_x] == 'P' || data->tmp[\
	data->exit_y - 1][data->exit_x] == 'P' || data->tmp[data->exit_y][\
	data->exit_x + 1] == 'P' || data->tmp[data->exit_y] \
	[data->exit_x - 1] == 'P'))
		print_error(data, "Path is not valid", 1);
}

int	main(int ac, char **av)
{
	int				fd;
	static t_mlx	data;

	if (ac != 2)
		print_error(&data, "Wrong number of arguments", 1);
	if (ber_checker(av) == 0)
		print_error(&data, "Invalid map name", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error(&data, "Invalid Map File", 1);
	data.map = map_to_string(NULL, fd, 0);
	if (data.map == NULL)
		print_error(&data, "Empty map", 1);
	close(fd);
	validater(&data, 0, 0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map_length(data.map) * 64,
			(map_height(data.map) * 64) + 64, "So_Long");
	render(&data);
	mlx_hook(data.win, 02, (1L << 0), key, &data);
	mlx_hook(data.win, 17, (1L << 2), exit_prog, &data);
	mlx_loop_hook(data.mlx, animation, &data);
	mlx_loop(data.mlx);
}
