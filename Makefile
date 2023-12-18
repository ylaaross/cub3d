# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 19:29:52 by asaber            #+#    #+#              #
#    Updated: 2023/12/17 17:35:28 by ylaaross         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d
CFLAGS	:=  -Wunreachable-code -Ofast #-fsanitize=address -g #-Wextra -Wall -Werror
LIBMLX	:= /Users/$(USER)/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=	cub3d.c draw.c put_pixel.c move.c player.c checks.c raycasting.c                 #parsing/Wall_check.c #parsing/ft_split.c #parsing/cube3d.c parsing/cube3d1.c parsing/cube3d2.c parsing/cube3d3.c parsing/cube3d4.c parsing/cube3d5.c parsing/get_next_line_utils.c parsing/get_next_line.c parsing/ft_substr.c parsing/file_store.c parsing/file_store1.c parsing/file_check.c parsing/ft_strdup.c parsing/ft_strstr.c parsing/ft_strstr1.c parsing/ft_strlen.c parsing/test_map.c parsing/test_map2.c parsing/var_check.c parsing/var_check1.c parsing/var_check2.c parsing/var_check3.c parsing/ft_strtrim.c parsing/ft_atoi.c parsing/size_calculate.c parsing/var_test.c parsing/map_create.c parsing/map_create1.c  #raycasting.c
OBJS	:= ${SRCS:.c=.o} lib_functions/ft_split.o lib_functions/ft_strlen.o                   #parsing/Wall_check.o #parsing/ft_split.o #parsing/cube3d.o parsing/cube3d1.o parsing/cube3d2.o parsing/cube3d3.o parsing/cube3d4.o parsing/cube3d5.o parsing/get_next_line_utils.o parsing/get_next_line.o parsing/ft_substr.o parsing/file_store.o parsing/file_store1.o parsing/file_check.o parsing/ft_strdup.o parsing/ft_strstr.o parsing/ft_strstr1.o parsing/ft_strlen.o parsing/test_map.o parsing/test_map2.o parsing/var_check.o parsing/var_check1.o parsing/var_check2.o parsing/var_check3.o parsing/ft_strtrim.o parsing/ft_atoi.o parsing/size_calculate.o parsing/var_test.o parsing/map_create.o parsing/map_create1.o

all:  $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS)  -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -Iinclude /Users/ylaaross/MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib" -framework Cocoa -framework OpenGL -framework IOKit $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx