SRC=main.c \
	map.c \
	map_2.c \
	setup.c
OBJ=${SRC:.c=.o}
NAME=fdf
FT=libft/libft.a
MLX=minilibx_macos/libmlx.a
LIBS=-framework OpenGL -framework AppKit -lm
FLAGS=-Wall -Werror -Wextra

all:
	make -C libft
	make -C minilibx_macos
	make $(NAME)

%.o: %.c
	cc -c $(FT) $(MLX) $(LIBS) $< -o $@

$(NAME): $(FT) $(OBJ)
	cc $(LIBS) $(FT) $(MLX) $(OBJ) -o $(NAME)

$(FT):
	make -C libft

$(MLX):
	make -C minilibx_macos

norm: $(SRC)
	norminette $<

clean:
	rm -rf *.o
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
	make fclean -C minilibx_macos

re: clean all

.PHONY: all clean fclean re
