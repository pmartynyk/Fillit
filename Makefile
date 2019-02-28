# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 09:38:43 by pmartyny          #+#    #+#              #
#    Updated: 2018/11/21 16:11:43 by pmartyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = fillit.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE =main.c\
		checkneighbors.c\
		validation.c\
		get_next_line.c\
		fill_map_list.c\
		print_map.c\
		algorithm.c\
		count.c\
		create_fin_map.c\
		ft_memalloc.c\
		ft_putendl.c\
		ft_strsub.c\
		ft_strlen.c\
		ft_strchr.c\
		ft_putchar.c

all: $(NAME)

$(NAME): 
	@$(CC) $(FLAGS) -c $(SOURCE)
	@$(CC) $(FLAGS) -o $(NAME) -I$(LIB) *.o

clean: 
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
