/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:46:54 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 16:57:21 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	original;

	original = dstsize;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst != '\0' && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	if (dstsize == '\0')
		return (ft_strlen(src) + original);
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (total);
	return (0);
}
