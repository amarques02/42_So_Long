/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:33:46 by amarques          #+#    #+#             */
/*   Updated: 2022/10/31 16:16:00 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	**map_to_string(char **map, int fd, int i)
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

void	map_cpy(t_mlx *data, int j, int i)
{
	data->tmp = malloc((data->h + 1) * sizeof(char *));
	if (!data->tmp)
		return ;
	while (data->map[j])
	{
		i = 0;
		data->tmp[j] = malloc((data->l + 2) * sizeof(char));
		while (data->map[j][i])
		{
			data->tmp[j][i] = data->map[j][i];
			i++;
		}
		data->tmp[j][i] = 0;
		j++;
	}
	data->tmp[j] = 0;
}
