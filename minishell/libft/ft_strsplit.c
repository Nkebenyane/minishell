/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:20:35 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/27 09:35:14 by mnkebeny         ###   ########.fr       */
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

char    **ft_strsplit(char const *s, char c)
{
	int z = 0;
    size_t  i;
    size_t  d;
    size_t  start;
    char    **str;

    str = NULL;
    i = 0;
    d = 0;

	if (c == ' ')
		z = ft_nwrds(s);
	else
	{
		while (s[i])
		{
			if (s[i] == c)
			{
				z++;
			}
			i++;
		}
	}
	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1))))
        return (NULL);
	i = 0;
	while (s[i] != '\0')
    {
        while (s[i] == c && s[i])
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        if (i > start)
        {
            str[d++] = ft_strsub(s, start, (i - start));
		}
        i++;
    }
    str[d] = NULL;
    return (str);
}
