/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:44:57 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/04 16:05:14 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	p = (void *)malloc(sizeof(void) * size);
	if (p != NULL)
	{
		ft_bzero(p, size);
		return (p);
	}
	return (NULL);
}
