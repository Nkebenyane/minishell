# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 08:23:40 by achauvea          #+#    #+#              #
#    Updated: 2018/09/13 12:33:28 by mnkebeny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell.a

SRC		=	ft_cd.c ft_exit.c ft_launch.c ft_execute.c get_next_line.c ft_env.c\
			
 
OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@gcc $(CFLAGS) -o minishell main.c $(NAME) libft/libft.a

all: $(NAME)

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) $(OBJ)
	@rm -rf ft_ls

re: fclean $(NAME)
