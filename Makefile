NAME = so_long

FILES = srcs/so_long.c\
	srcs/maps.c

# B_FILES = sera.c

COMPILER = gcc
MLX = ./MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a
CFLAGS =
# -pedantic -Wconversion -g3 -DDEBUG
# CFLAGS = -Wall -Wextra -Werror
INC = -I ./srcs/ -I ./MLX42/include/MLX42
MLXFLAGS = $(MLX) $(INC) -ldl -lglfw -pthread -lm -g

OBJS = $(FILES:%.c=%.o)

all:$(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(CFLAGS) $(OBJS) $(INC) $(MLXFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft/ --no-print-directory

$(MLX):
	cmake -S ./MLX42 -B ./MLX42/build
	cmake --build ./MLX42/build -j4

clean: libclean
	rm -f $(OBJS) $(OBJS_B)

libclean:
	@make clean -C ./libft --no-print-directory

fclean: clean libfclean mlxfclean
	rm -f $(NAME) 

libfclean:
	@make fclean -C ./libft --no-print-directory

mlxfclean: 
	@make clean -C ./MLX42/build --no-print-directory 

re: fclean $(NAME)

%.o: %.c
	@$(COMPILER) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
