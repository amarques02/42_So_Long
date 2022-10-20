/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:33:46 by amarques          #+#    #+#             */
/*   Updated: 2022/09/30 18:12:55 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char **map_to_string(char **map, int fd, int i)
{
	char	*str;
	
	str = get_next_line(fd);
	if (str)
		map = map_to_string(map, fd, i + 1);
	if (!map && i != 0)
		map = malloc((i + 1) * sizeof(char *));
	if (!map)
		return (0);
	map[i] = str;
	return (map);
}
