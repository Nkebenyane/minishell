/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:14:40 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/22 07:43:40 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arraydel(char ***arr)
{
	int i;

	i = 0;
	if (!*arr)
		return (1);
	while ((*arr)[i])
		i++;
	i--;
	while (i >= 0)
		ft_strdel(&(*arr)[i--]);
	free(*arr);
	*arr = NULL;
	return (1);
}
