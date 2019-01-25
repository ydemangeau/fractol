CC=cc
FLAG=-Wall -Wextra -Werror
LIB_DIR=./libft
LIB=./libft/libft.a
EXEC=fractol
SRC=src/main.c\
	src/mandelbrot.c\
	src/julia.c\
	src/tricorn.c\
	src/event.c

all:$(EXEC)

$(EXEC) :$(SRC)
		@(cd $(LIB_DIR) && $(MAKE))
		$(CC) $(FLAG) -I /usr/local/include  $(SRC) $(LIB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(EXEC)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
		@(cd $(LIB_DIR) && $(MAKE) $@)
		rm -rf $(EXEC)

re: fclean all

.PHONY : all, clean, fclean, re
