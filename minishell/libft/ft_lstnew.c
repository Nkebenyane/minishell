/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:47:25 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/06/05 09:16:10 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	newlink = (t_list *)ft_memalloc(sizeof(t_list));
	if (newlink == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		newlink->content = NULL;
	}
	else
	{
		newlink->content = malloc(sizeof(void const) * content_size);
		ft_memcpy(newlink->content, content, content_size);
	}
	newlink->content_size = content_size;
	newlink->next = NULL;
	return (newlink);
}
