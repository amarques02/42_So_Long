/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:37:27 by amarques          #+#    #+#             */
/*   Updated: 2022/10/24 13:13:12 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ber_checker(char **av)
{
	char *dot;
	
	dot = ft_strrchr(av[1], '.');
	if (dot && !ft_strncmp(dot, ".ber", 5))
		return(1);
	return (0);
}
