/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 09:29:07 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/07 16:49:15 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_length(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	return (i);
}

int		get_chr(char **str, char **line, int r)
{
	int			i;
	char		*hold;

	if (*str == NULL)
		return (0);
	i = ft_length(str);
	if ((*str)[i] != '\0')
	{
		(*line) = ft_strsub(*str, 0, i);
		hold = ft_strdup(*str + i + 1);
		free(*str);
		*str = ft_strdup(hold);
		free(hold);
		return (1);
	}
	if ((*str)[i] == '\0' && r == 0)
	{
		(*line) = ft_strdup(*str);
		hold = ft_strsub(*str, i, ft_strlen(*str));
		free(*str);
		*str = ft_strdup(hold);
		free(hold);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static char		*temp = NULL;
	char			*temp2;
	char			buffer[BUFF_SIZE + 1];

	i = 1;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((get_chr(&temp, &(*line), i) == 0))
	{
		if ((i = read(fd, buffer, BUFF_SIZE)) < 0)
			return (-1);
		buffer[i] = '\0';
		if (temp == NULL)
			temp = ft_strdup(buffer);
		else
		{
			temp2 = temp;
			temp = ft_strjoin(temp2, buffer);
			free(temp2);
		}
	}
	if (ft_strlen(*line) > 0 || i > 0)
		return (1);
	return (0);
}
