/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:34:37 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/07 14:28:21 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;

	dptr = dst;
	sptr = src;
	while (n--)
	{
		*dptr++ = *sptr++;
	}
	return (dst);
}
