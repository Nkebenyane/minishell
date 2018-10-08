/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:34:54 by mnkebeny          #+#    #+#             */
/*   Updated: 2018/09/13 17:22:52 by mnkebeny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

#define BUF_SIZE 1025

char	**g_env;


void	ft_cpy(char **env);
int		ft_cd(char * argc, char **args);
int		ft_exit(int argc, char **args);
int		ft_env(int argc, char **args);

int		ft_launch(char **p, char **args);
int		ft_execute(char *p, char **args);
char	*ft_read_line(void);

int		get_next_line(const int fd, char **line);
void	ft_split_line(char *line);

#endif
