/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:12:59 by amarques          #+#    #+#             */
/*   Updated: 2022/10/31 16:14:46 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	**img;
	char	**map;
	char	**tmp;
	int		player_x;
	int		player_y;
	int		collectable;
	void	*animation;
	void	*animation_e;
	int		e_count;
	int		c_count;
	int		p_count;
	int		l;
	int		h;
	int		exit_x;
	int		exit_y;
}			t_mlx;

int		ber_checker(char **av);
int		chr_counter(t_mlx *data, int j, int i);
int		format_check(t_mlx *data, int i, int j);
int		border_check(t_mlx *data, int i);
void	path_checker(char **map, int x, int y);
char	**map_to_string(char **map, int fd, int i);
int		map_length(char **map);
int		map_height(char **map);
void	render(t_mlx *data);
int		exit_game(t_mlx	*data);
int		key(int keycode, void *param, t_mlx *data);
int		animation(void *param);
void	load_img(t_mlx *data, int i);
void	load_img2(t_mlx *data, int i);
void	load_img3(t_mlx *data, int i);
int		print_error(t_mlx *data, char *str, int status);
void	map_cpy(t_mlx *data, int j, int i);

#endif