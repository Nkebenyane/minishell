/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 07:32:29 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/22 08:05:58 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char ***arr)
{
	int		i;
	char	**new;

	i = 0;
	while ((*arr)[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while ((*arr)[++i])
		new[i] = ft_strdup((*arr)[i]);
	new[i] = NULL;
	ft_arraydel(arr);
	return (new);
}

