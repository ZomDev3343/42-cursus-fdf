SRC=main.c \
	map.c \
	map_2.c \
	input.c \
	render.c \
	window.c \
	utils.c \
	draw.c \
	vector.c \
	matrix.c \
	matrix_2.c \
	camera.c \
	setup.c
OBJ=${SRC:.c=.o}
NAME=fdf
FT=./libft/libft.a
MLX=./mlx/libmlx.a
LIBS=-I/usr/include -lXext -lX11 -lm -lz
FLAGS=-Wall -Werror -Wextra

all:
	make -C libft
	make -C mlx
	make $(NAME)

%.o: %.c
	cc -c $(FT) $(MLX) $(LIBS) -g $< -o $@

$(NAME): $(FT) $(OBJ)
	cc $(OBJ) $(FT) $(MLX) $(LIBS) -o $(NAME)

$(FT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	rm -rf *.o
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
	make fclean -C mlx

re: clean all

.PHONY: all clean fclean re
