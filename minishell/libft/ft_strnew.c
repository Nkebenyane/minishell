/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 12:11:12 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/31 15:36:29 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = ft_memalloc((size) + 1);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
	else
		return (NULL);
}
