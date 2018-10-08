/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:11:58 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/01 12:44:49 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0' && (i + ft_strlen(needle) <= len))
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == ft_strlen(needle) - 1)
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
