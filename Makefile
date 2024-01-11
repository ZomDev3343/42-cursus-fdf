SRC=
OBJ={SRC:.c=.o}
NAME=fdf
FT=libft/libft.a
MLX=minilibx_macos/libmlx.a
LIBS=-framework OpenGL -framework AppKit -lm
FLAGS=-Wall -Werror -Wextra -c

all:
	make -C libft
	make -C minilibx_macos
	make $(NAME)

%.o: %.c
	cc $(FLAGS) $(LIBS) $< -o $@

$(NAME): $(OBJ)
	cc $(FLAGS) (LIBS) $(FT) $(MLX) $(OBJ) -o $(NAME)
