# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2023/12/12 09:07:39 by aherrman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c\
ft_error.c\
ft_free.c\
valid_arg.c\
map.c\
utils.c\
test.c

SRCSB = 

OBJSB = $(addprefix src/bonus/,$(SRCST:.c=.o))


OBJS = $(addprefix src/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

RM = rm -rf

LIBS = include/libft/libft.a include/.MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
INC = -I include.MLX42/include


.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) 
	make all -C ./include/libft
	cd ./include/.MLX42 && cmake -B build && cmake --build build -j4
	gcc $(FLAG) $(OBJS) $(LIBS) -o $(NAME)

debug:	$(OBJS)
	make all -C ./src/libft
	cd ./include/.MLX42 && cmake -B build && cmake --build build -j4
	gcc $(FLAG) -fsanitize=address $(OBJS) $(LIBS) -o $(NAME)

test: $(OBJS) $(OBJST)
	make all -C ./include/libft
	cd ./include/.MLX42 && cmake -B build && cmake --build build -j4
	gcc $(FLAG) $(OBJS) $(OBJST) $(LIBS) -o $(NAME)
	
testd: $(OBJS) $(OBJST)
	make all -C ./include/libft
	cd ./include/.MLX42 && cmake -B build && cmake --build build -j4
	gcc $(FLAG) -fsanitize=address $(OBJS) $(OBJST) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJST)
#	make clean -C /Users/aherrman/goinfre/.MLX42/build
	make clean -C ./include/libft


fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./include/libft
#	make clean -C /Users/aherrman/goinfre/.MLX42/build
	
re:	fclean all

ret: fclean test
