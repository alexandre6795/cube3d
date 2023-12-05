# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2023/12/05 10:51:33 by aherrman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube

SRCS =
		
		
SRCSB = 

OBJSB = $(addprefix src/bonus/,$(SRCST:.c=.o))


OBJS = $(addprefix src/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

RM = rm -rf

LIBS = include/libft/libft.a include/.mlx42/build/libmlx42.a -lglfw -L"/Users/aherrman/.brew/opt/glfw/lib/"
INC = -I include.mlx42/include


.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) 
	make all -C ./include/libft
	make -C /Users/aherrman/goinfre/.mlx42/build
	gcc $(FLAG) $(OBJS) $(LIBS) -o $(NAME)

debug:	$(OBJS)
	make all -C ./src/libft
	make -C /Users/aherrman/goinfre/.mlx42/build
	gcc $(FLAG) -fsanitize=address $(OBJS) $(LIBS) -o $(NAME)

test: $(OBJS) $(OBJST)
	make all -C ./src/libft
	make -C /Users/aherrman/goinfre/.mlx42/build
	gcc $(FLAG) $(OBJS) $(OBJST) $(LIBS) -o $(NAME)
	
testd: $(OBJS) $(OBJST)
	make all -C ./src/libft
	make -C /Users/aherrman/goinfre/.mlx42/build
	gcc $(FLAG) -fsanitize=address $(OBJS) $(OBJST) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJST)
	make clean -C /Users/aherrman/goinfre/.mlx42/build
	make clean -C ./src/libft


fclean:	clean
	$(RM) $(NAME)
	make fclean -C ./src/libft
	make clean -C /Users/aherrman/goinfre/.mlx42/build
	
re:	fclean all

ret: fclean test
