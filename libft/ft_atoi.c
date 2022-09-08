/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:20:53 by amarques          #+#    #+#             */
/*   Updated: 2022/03/07 17:40:32 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	long long	result;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 2147483647)
			return (-1);
		if (result < -2147483648)
			return (0);
		result = (result * 10) + (j * (str[i++] - '0'));
	}
	return (result);
}
