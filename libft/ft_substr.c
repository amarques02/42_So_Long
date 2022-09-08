/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:07:49 by amarques          #+#    #+#             */
/*   Updated: 2022/03/07 17:34:58 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	j = 0;
	while (start < ft_strlen(s) && j < len)
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
