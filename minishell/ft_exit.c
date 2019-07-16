/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 14:08:17 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 11:58:22 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **argv)
{
	unsigned char exit_val;

	exit_val = 0;
	if (argv && argv[1])
	{
		if (ft_isdigit(argv[1][0]))
			exit_val = ft_atoi(argv[1]);
		else
		{
			ft_putendl("exit: Expression Syntax.");
			return ;
		}
	}
	ft_arraydel(&g_env);
	exit(exit_val);
}
