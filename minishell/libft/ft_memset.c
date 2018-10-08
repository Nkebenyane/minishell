/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 07:55:23 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/01 12:41:26 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ((char*)str);
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
