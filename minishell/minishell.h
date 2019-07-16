/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:34:54 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/28 10:21:44 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

char	**g_env;
void	ft_cpy(char **env);
int		env_len(char **args);
char	*ft_get_path(char *s, char **env);
int		ft_cd(char **args);
int		ft_echo(char **args);
void	ft_exit(char **args);
void	ft_clear(void);
char	*ft_getenv(const char *args);
void	ft_printenv(void);

int		ft_setenv(char **args);
int		ft_unsetenv(char **args);

int		ft_launch(char **args);
int		ft_execute(char **args);

int		get_next_line(const int fd, char **line);

#endif
