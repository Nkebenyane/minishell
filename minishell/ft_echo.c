/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:29:39 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/27 16:47:55 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		no_qout(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			write(1, &str[i], 1);
		i++;
	}
}

void		ft_print(char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		no_qout(args[i++]);
		ft_putchar(' ');
	}
	ft_putstr("\n");
}

int			ft_echo(char **args)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!args || !args[1])
		ft_putendl("\b");
	else if (ft_strncmp(&args[1][k], "$", 1) == 0)
	{
		k++;
		while (g_env[i])
			if (ft_strstr(g_env[i], &args[1][k]))
			{
				ft_putendl(ft_strchr(g_env[i], '=') + 1);
				break ;
			}
			else
				i++;
	}
	else
		ft_print(args);
	return (0);
}
