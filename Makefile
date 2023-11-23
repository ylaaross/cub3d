CC = cc

CFLAGS = -Wall -Wextra -Werror 

ARGS= -Iinclude -lglfw   -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib"

MLX42 = /Users/ylaaross/MLX42/build/libmlx42.a 

NAME = cub3D

SRC =   Wall_check.c ft_split.c cube3d.c cube3d1.c cube3d2.c cube3d3.c cube3d4.c cube3d5.c get_next_line_utils.c get_next_line.c ft_substr.c file_store.c file_store1.c file_check.c ft_strdup.c ft_strstr.c ft_strstr1.c ft_strlen.c test_map.c test_map2.c var_check.c var_check1.c var_check2.c var_check3.c ft_strtrim.c ft_atoi.c size_calculate.c var_test.c map_create.c map_create1.c

OBJS =  $(SRC:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS)  $(ARGS) $(MLX42) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re