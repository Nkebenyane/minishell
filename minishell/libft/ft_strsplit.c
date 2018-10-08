/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:20:35 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/08/26 17:37:11 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nwrds(char const *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && !(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		{
			count++;
			while  (s[i] && !(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char		*ft_strndup(char const *s, int len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**arr;
	int		j;
	int 	i;
	int		x;

	arr = (char **)malloc(sizeof(char *) * (ft_nwrds(str) + 1));
	i = 0;
	j = 0;
	x = 0;
	while (x < ft_nwrds(str))
	{
		while  (str[i] && (str[i] == c))
			i++;
		j = i;
 		while (str[i] && !(str[i] == c))
			i++;
		if (j < i)
			arr[x++] = ft_strndup(str + j, i - j);
	}
	arr[x] = NULL;
	return (arr);
}

