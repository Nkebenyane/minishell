/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:46:44 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 11:16:44 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			env_len(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_cpy(char **av)
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
	g_env[i] = NULL;
}

void		ft_printenv(void)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
}
