/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 03:45:37 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 09:09:40 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_unsetenv(char **args)
{
	int		i;

	i = -1;
	if (!args[1])
	{
		ft_putendl("Environment Error : No path found !");
		return (1);
	}
	while (g_env[++i])
	{
		if (ft_strstr(g_env[i], args[1]))
		{
			while (g_env[i + 1])
			{
				g_env[i] = ft_strdup(g_env[1 + i]);
				i++;
			}
			g_env[i] = NULL;
		}
	}
	return (0);
}
