/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:25:26 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 17:05:16 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (copy)
	{
		ft_strcpy(copy, s1);
		return (copy);
	}
	return (0);
}
