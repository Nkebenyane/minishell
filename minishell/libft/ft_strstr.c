/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 07:25:59 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/30 07:43:35 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	p = NULL;
	if (needle[0] == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			p = ((char*)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return (p);
		i++;
	}
	return (NULL);
}
