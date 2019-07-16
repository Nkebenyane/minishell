/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:04:50 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/27 17:42:37 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_array_join(char ***arr, char *str)
{
	int		i;
	char	**new;

	i = 0;
	if (!*arr)
	{
		if (!(new = (char **)malloc(sizeof(char*) * 2)))
			return (NULL);
		new[0] = ft_strdup(str);
		new[1] = NULL;
		return (new);
	}
	while ((*arr)[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = -1;
	while ((*arr)[++i])
		new[i] = ft_strdup((*arr)[i]);
	new[i++] = ft_strdup(str);
	new[i] = NULL;
	ft_arraydel(arr);
	return (new);
}
