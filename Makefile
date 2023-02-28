# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skaur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 12:48:10 by skaur             #+#    #+#              #
#    Updated: 2023/02/28 11:47:17 by skaur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

RM = rm -rf

SRCS =  pipex.c\
        pipex_utils.c\
        pipex_eval.c\
        ft_split.c ft_strjoin.c ft_strlen.c\
        ft_strncmp.c\
        ft_strnstr.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

