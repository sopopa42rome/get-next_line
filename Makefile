# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 19:08:50 by sopopa            #+#    #+#              #
#    Updated: 2022/08/18 16:38:05 by sopopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = get_next_line.c \
		get_next_line_utils.c \


FLAGS =	-Wall -Werror -Wextra
CC = gcc
OBJS = $(SRCS:.c=.o)
BONUS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
	
	
OBJS_BONUS = $(BONUS:.c=.o)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)
	ar rcs get_next_line.a $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -f $(NAME)
re: fclean all
bonus:
	$(CC) $(FLAGS) $(BONUS)
	ar rcs get_next_line_bonus.a $(OBJS_BONUS)