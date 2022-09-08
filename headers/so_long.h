/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:12:59 by amarques          #+#    #+#             */
/*   Updated: 2022/09/07 16:47:28 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include "../libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img[7];
}	t_mlx; 

typedef struct s_map
{
}	t_map;

int	ber_checker(char **av);

#endif