/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:21:45 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/13 17:22:57 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int env_len(char **str)
{
	int i;
	i = 0;

	while (str[i])
		i++;

	return (i);
}

void	ft_cpy(char **av)
{
	int		i;

	g_env = (char **)malloc(sizeof(char*) * env_len(av) + 1);
	i = 0;
	while (*av != NULL)
	{
		g_env[i] = ft_strdup(*av);
		i++;
		av++;
	}
/*	g_env[i] = NULL;
	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}*/
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	char *line;

	line = NULL;
	ft_putstr("\033[2J\033[H");
	ft_cpy(envp);
	while (1)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		ft_execute(*av,&line);
		
		free(line);
	}
}
