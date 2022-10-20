/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:02:29 by amarques          #+#    #+#             */
/*   Updated: 2022/10/20 12:09:32 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	map_length(char **map)
{
	int	i;
	
	i = 0;
	while (map[0][i])
		i++;
	return(i - 1);
}

int	map_height(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
		i++;
	return(i);
}