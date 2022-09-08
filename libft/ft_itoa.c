/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:40:47 by amarques          #+#    #+#             */
/*   Updated: 2022/03/07 12:21:51 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_dig(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_count_dig(n / 10));
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = (long int)n;
	i = ft_count_dig(nb) + (nb < 0);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
