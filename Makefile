NAME = fractol

LIBFTA = libft.a

FRACTOL_H =	-I includes/

LIBFT_H = 	-I src/libft/

CFLAGS = -Wall -Werror -Wextra -g

CC = clang

MLX = -lmlx -framework OpenGL -framework AppKit

COMP =	$(CC) $(CFLAGS) $(FRACTOL_H) $(LIB_DIR)$(LIBFTA)

SRC_DIR =	src/

OBJ_DIR =	obj/

LIB_DIR = src/libft/

SRCS = fractol.c print_fract.c func_key_press.c

CFIND =	$(SRCS:%=$(SRC_DIR)%)

OFILE =	$(SRCS:%.c=%.o)

OBJ =	$(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFTA) .
	@mv $(LIBFTA) $(NAME)
	$(COMP) $(MLX) $(addprefix $(SRC_DIR), $(SRCS)) -o $(NAME)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all
