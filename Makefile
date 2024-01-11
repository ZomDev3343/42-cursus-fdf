SRC=
OBJ={SRC:.c=.o}
NAME=fdf
FT=libft/libft.a

all:
	make -C libft
	make $(NAME)
