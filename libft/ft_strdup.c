/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:50:51 by amarques          #+#    #+#             */
/*   Updated: 2022/03/01 13:05:19 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = ft_calloc(ft_strlen(s1) + 1, sizeof (char));
	if (!s2)
		return (NULL);
	s2 = ft_memmove(s2, s1, ft_strlen(s1));
	return (s2);
}
