/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:27:22 by amarques          #+#    #+#             */
/*   Updated: 2022/04/07 11:46:22 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[counter])
	{
		write(1, &str[counter], 1);
		counter++;
	}
	return (counter);
}

int	ft_putnbr(int nb)
{
	int				counter;
	unsigned int	nbr;

	counter = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
		counter++;
	}
	else
		nbr = (unsigned int)nb;
	if (nbr > 9)
		counter = counter + ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
	counter++;
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
		counter = counter + ft_putnbr_unsigned(nb / 10);
	ft_putchar((char)(nb % 10 + 48));
	counter++;
	return (counter);
}
