/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:12:59 by amarques          #+#    #+#             */
/*   Updated: 2022/10/20 13:55:25 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	**img;
	char	**map;
}	t_mlx; 

int	ber_checker(char **av);
char **map_to_string(char **map, int fd, int i);
int	map_length(char **map);
int	map_height(char **map);
void render(t_mlx *data);
int exit_game(t_mlx	*data);
int key(int keycode, void *param);

#endif