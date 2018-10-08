/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:45:30 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/13 17:22:50 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_launch(char **path, char **args)
{
	pid_t	child;
	int i;

	i = 0;
	(void)path;	
	child = fork();
	if (child == 0)
	{
//		ft_cpy(path);
		printf("%s",*g_env);
		if (execve(*path, args, g_env) == -1)
			perror("it's crazy");
		exit(0);
	}
	else
		wait(&child);
	return (0);
}
