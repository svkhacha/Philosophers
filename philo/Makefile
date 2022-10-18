# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 22:41:44 by svkhacha          #+#    #+#              #
#    Updated: 2022/10/15 23:01:48 by svkhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo
SRCS 	= $(wildcard *.c)
OBJS 	= $(patsubst %.c, %.o, $(SRCS))
CC 	 	= 	cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created !$(END)"

clean :
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files deleted !$(END)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)All deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re

#Makefile_Colors
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED=\033[0;31m
END = \033[0m


