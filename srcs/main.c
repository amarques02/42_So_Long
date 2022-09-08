/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:13:04 by amarques          #+#    #+#             */
/*   Updated: 2022/09/07 16:54:31 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h" 

int	main(int ac, char **av)
{
	if (ac != 2)
		return(ft_printf("Use:./so_long <path/to/map>\n"));
	if (ber_checker(av) == 0)
		return(ft_printf("Wrong file type\n"));
}
