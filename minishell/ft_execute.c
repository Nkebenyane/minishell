/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:44:45 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/13 17:22:45 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char 	*builtin_str[] = {
	"cd",
	"exit",
	"env"
};

int		(*builtin_func[]) (int, char **) = {
	&ft_cd,
	&ft_exit,
	&ft_env
};

int		ft_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
};

int 	ft_execute(char *path, char **args)
{
	int i;

	i = 0;
	if (args[0] == NULL)
		return (1);
	while (i < ft_builtins())
	{
		if (ft_strcmp(args[i],builtin_str[i]) == 0)
			return (*builtin_func[i])(0, args);
		i++;
	}
	return (ft_launch(path, args));
}*/

int 	ft_execute(char *path, char **args)
{
	(void)path;
//	path = *g_env;
//	ft_putendl(path);
	if (ft_strcmp(*args, "cd") == 0)
		ft_cd(path, args);
	return (ft_launch(&path, args));
}
