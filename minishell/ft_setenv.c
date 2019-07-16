/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 20:31:40 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/27 17:42:47 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_replace(char ***env, char **s, char **args)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**arr;

	i = 0;
	while ((*env)[i])
		i++;
	arr = (char **)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while ((*env)[++i])
		if (!ft_strncmp((*env)[i], *s, ft_strlen(*s)))
		{
			tmp = ft_strcat(*s, "=");
			path = ft_strjoin(tmp, args[2]);
			arr[i] = ft_strdup(path);
			ft_strdel(&path);
		}
		else
			arr[i] = ft_strdup((*env)[i]);
	arr[i] = NULL;
	ft_arraydel(env);
	ft_strdel(s);
	*env = ft_arraydup(&arr);
	return (1);
}

int			ft_setenv(char **args)
{
	int		i;
	char	*tmp;
	char	*path;

	i = -1;
	if (!args || !args[1] || !args[2])
	{
		ft_putendl("Environment Error : No path found!");
		return (0);
	}
	while (g_env[++i])
		if (ft_strstr(g_env[i], args[1]))
			return (ft_replace(&g_env, &args[1], args));
	tmp = ft_strcat(args[1], "=");
	path = ft_strjoin(tmp, args[2]);
	g_env = ft_array_join(&g_env, path);
	ft_strdel(&path);
	return (0);
}
