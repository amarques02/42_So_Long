/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:38:05 by amarques          #+#    #+#             */
/*   Updated: 2022/04/05 17:25:59 by amarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	size_t	count;

	if (!s)
		return (NULL);
	count = wordcount(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	str = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (str != s)
				*(res++) = ft_substr(str, 0, s - str);
			str = (char *)s + 1;
		}
		s++;
	}
	if (str != s)
		*(res++) = ft_substr(str, 0, s - str);
	*res = 0;
	return (res - count);
}
