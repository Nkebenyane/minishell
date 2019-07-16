/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:06:19 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 17:03:19 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int		i;
	char				*new_str;

	if (!s)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str != '\0')
	{
		while (s[i] != '\0')
		{
			new_str[i] = f(s[i]);
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (0);
}
