/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:50:41 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/05/29 12:29:09 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;

	while (n-- > 0)
	{
		sptr = (unsigned char*)s;
		if (*sptr == (unsigned char)c)
		{
			return (sptr);
		}
		s++;
	}
	return (NULL);
}
