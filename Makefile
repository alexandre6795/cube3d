# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2024/01/22 11:52:30 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c\
ft_error.c\
ft_free.c\
valid_arg.c\
map.c\
utils.c\
ft_flood_fill.c\
create_world.c\
create_minimap.c\
create_minimapuser.c\
image_on_minimap.c\
textures.c\
drawline.c\
rgb.c\
loop.c\
move.c\
move2.c\
move_utils.c\
ray.c\
utils_ray.c\
pi_utils.c\
3d_world.c\
cursor.c\
wall_collision.c\
test.c

SRCSB = 

OBJSB = $(addprefix src/bonus/,$(SRCST:.c=.o))


OBJS = $(addprefix src/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra -Ofast

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
	make all -C ./include/libft
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
#	rm -rf ./include/.MLX42/build
#	make clean -C /Users/aherrman/goinfre/.MLX42/build

clean_mlx:
	rm -rf ./include/.MLX42/build
	
re:	fclean all

re_mlx:	clean_mlx fclean all

ret: fclean test
