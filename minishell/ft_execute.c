/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:44:45 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 10:42:30 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(char **args)
{
	if (!args[0])
		return (1);
	if (ft_strcmp(args[0], "env") == 0)
		ft_printenv();
	else if (ft_strcmp(args[0], "setenv") == 0)
		ft_setenv(args);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		ft_unsetenv(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		ft_cd(args);
	else if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(args[0], "exit") == 0)
		ft_exit(args);
	else if (ft_strcmp(args[0], "clear") == 0)
		ft_clear();
	else
		ft_launch(args);
	return (0);
}
