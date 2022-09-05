/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:27:45 by amarques          #+#    #+#             */
/*   Updated: 2022/04/07 11:46:29 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

int		ft_printf(const char *format, ...);
void	ft_conversion(va_list *args, const char *format, int i, int *counter);
int		ft_puthex_low(unsigned long nb);
int		ft_puthex_up(unsigned long nb);
int		ft_puthex_ptr(void *nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);

#endif
