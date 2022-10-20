/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:54:58 by amarques          #+#    #+#             */
/*   Updated: 2022/10/20 13:55:10 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int key(int keycode, void *param)
{
	t_mlx	*data;
	data = param;
	/* ft_printf("%d\n", keycode); */
	if (keycode == 65307)
		exit_game(data);

	return (0);
}