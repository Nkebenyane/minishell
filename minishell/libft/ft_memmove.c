/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:43:32 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 16:49:28 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;

	dptr = dst;
	sptr = src;
	if (sptr < dptr)
		while (n--)
		{
			dptr[n] = sptr[n];
		}
	else
		ft_memcpy(dptr, sptr, n);
	return (dst);
}
