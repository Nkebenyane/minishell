/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:45:30 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 11:22:51 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_exist(char **path, char *args)
{
	int		i;
	char	*tmp;
	char	*exist;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		exist = ft_strjoin(tmp, args);
		ft_strdel(&tmp);
		if (access(exist, F_OK) == 0)
			break ;
		else
		{
			tmp = exist;
			exist = &args[0];
			ft_strdel(&tmp);
		}
	}
	return (exist);
}

char		*ft_get_path(char *args, char **env)
{
	int		i;
	char	**path;
	char	*exist;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 4))
		++i;
	if (!env[i])
	{
		ft_putendl("Environment Error : No path found !");
		return (0);
	}
	path = ft_strsplit(env[i] + 5, ':');
	exist = ft_exist(path, args);
	ft_arraydel(&path);
	return (exist);
}

int			ft_launch(char **args)
{
	pid_t	child;
	char	*path;

	path = ft_get_path(args[0], g_env);
	child = fork();
	if (child == 0)
	{
		if (execve(path, args, g_env) == -1)
			ft_putendl("minishell: Bad addrss");
		ft_strdel(&path);
		exit(0);
	}
	else
		wait(&child);
	if (ft_strcmp(path, args[0]))
		ft_strdel(&path);
	return (0);
}
