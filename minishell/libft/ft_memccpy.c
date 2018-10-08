/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:32:07 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 16:45:24 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dptr;
	char		*sptr;
	size_t		i;

	dptr = (char*)dst;
	sptr = (char*)src;
	i = 0;
	while (i < n)
	{
		dptr[i] = sptr[i];
		if ((unsigned char)sptr[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
