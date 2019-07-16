/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:21:45 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 10:29:48 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int ac, char **av, char **envp)
{
	char	*line;
	char	**buf;

	(void)ac;
	(void)av;
	buf = NULL;
	line = NULL;
	ft_putstr("\033[2J\033[H");
	ft_cpy(envp);
	while (1)
	{
		ft_putstr("Maipato$>");
		get_next_line(0, &line);
		buf = ft_strsplit(line, ' ');
		ft_execute(buf);
		ft_arraydel(&buf);
		ft_strdel(&line);
	}
	return (0);
}
