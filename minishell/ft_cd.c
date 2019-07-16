/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:50:59 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 11:58:18 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_swap(char *name, char *value)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (g_env[++i])
	{
		if (ft_strchr(g_env[i], '='))
		{
			j = 0;
			while (g_env[i][j] != '=' && g_env[i][j])
				j++;
			s = ft_strnew(j);
			s = ft_strncpy(s, g_env[i], j);
			if (ft_strcmp(s, name) == 0)
				g_env[i] = ft_strjoin(name, value);
			ft_strdel(&s);
		}
	}
}

void		ft_perv(char **this)
{
	char	cwd[1024];
	int		i;
	char	*send;

	i = -1;
	send = NULL;
	while (g_env[++i])
		if (ft_strstr(g_env[i], "OLDPWD="))
		{
			this = ft_strsplit(g_env[i], '=');
			break ;
		}
	getcwd(cwd, sizeof(cwd));
	chdir(this[1]);
	send = ft_strjoin("=", this[1]);
	ft_swap("PWD", send);
	ft_strdel(&send);
	send = ft_strjoin("=", cwd);
	ft_swap("OLDPWD", send);
	ft_strdel(&send);
	ft_putendl(this[1]);
	ft_arraydel(&this);
}

void		ft_home(char **this)
{
	char	cwd[1024];
	int		i;
	char	*send;

	i = -1;
	send = NULL;
	while (g_env[++i])
		if (ft_strstr(g_env[i], "HOME="))
		{
			this = ft_strsplit(g_env[i], '=');
			break ;
		}
	getcwd(cwd, sizeof(cwd));
	chdir(this[1]);
	send = ft_strjoin("=", cwd);
	ft_swap("OLDPWD", send);
	ft_strdel(&send);
	send = ft_strjoin("=", this[1]);
	ft_swap("PWD", send);
	ft_strdel(&send);
	ft_arraydel(&this);
}

void		ft_dot(char **this)
{
	char	cwd[1024];
	int		i;
	char	*send;

	i = -1;
	send = NULL;
	while (g_env[++i])
		if (ft_strstr(g_env[i], "PWD="))
		{
			this = ft_strsplit(g_env[i], '=');
			break ;
		}
	getcwd(cwd, sizeof(cwd));
	send = ft_strjoin("=", cwd);
	ft_swap("PWD", send);
	ft_strdel(&send);
	send = ft_strjoin("=", this[1]);
	ft_swap("OLDPWD", send);
	ft_strdel(&send);
	ft_arraydel(&this);
}

int			ft_cd(char **args)
{
	char	**this;

	this = NULL;
	if (args[0] && args[1] == NULL)
		ft_home(this);
	else if (ft_strcmp(args[1], "-") == 0)
		ft_perv(this);
	else if (ft_strcmp(args[1], "~") == 0)
		ft_home(this);
	else if (chdir(args[1]) == 0)
		ft_dot(this);
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(args[1]);
	}
	return (0);
}
