/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:13:04 by amarques          #+#    #+#             */
/*   Updated: 2022/10/24 16:38:03 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h" 

int	main(int ac, char **av)
{
	int fd;
	static t_mlx	data;

	if (ac != 2)
		return(ft_printf("Use:./so_long <path/to/map>\n"));
	if (ber_checker(av) == 0)
		return(ft_printf("Wrong file type\n"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return(ft_printf("File doesn't exist\n"));
	data.map = map_to_string(NULL, fd, 0);
	if (data.map == NULL)
		return (ft_printf("Error\n"));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map_length(data.map) * 64, \
	map_height(data.map) * 64, "So Long");
	mlx_hook(data.win, 02, (1L<<0), key, &data);
	mlx_hook(data.win, 17, (1L<<2), exit_game, &data);
	render(&data);
	mlx_loop(data.mlx);
}
