CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MANDATORY_DIR	= source/Mandatory
BONUS_DIR		= source/Bonus

MLX_FLAGS	=  -lmlx -framework OpenGL -framework AppKit -lm 

MANDATORY_SRC	= $(MANDATORY_DIR)/main.c \
				  $(MANDATORY_DIR)/julia.c \
				  $(MANDATORY_DIR)/init.c \
				  $(MANDATORY_DIR)/draw.c \
				  $(MANDATORY_DIR)/utils.c \
				  $(MANDATORY_DIR)/mandelbrot.c \
				  $(MANDATORY_DIR)/mouse_and_keys.c \
				  $(MANDATORY_DIR)/is_valid_float.c \
				  $(MANDATORY_DIR)/helper.c

BONUS_SRC	= $(BONUS_DIR)/draw_bonus.c \
			  $(BONUS_DIR)/init_bonus.c \
			  $(BONUS_DIR)/julia_bonus.c \
			  $(BONUS_DIR)/mandelbrot_bonus.c \
			  $(BONUS_DIR)/mouse_and_keys_bonus.c \
			  $(BONUS_DIR)/tricorn_bonus.c \
			  $(BONUS_DIR)/utils_bonus.c \
			  $(BONUS_DIR)/is_valid_float_bonus.c \
			  $(BONUS_DIR)/fractal_bonus.c \
			  $(BONUS_DIR)/main_bonus.c \
			  $(BONUS_DIR)/helper_bonus.c


MANDATORY_OBJS	= $(MANDATORY_SRC:.c=.o)
BONUS_OBJS		= $(BONUS_SRC:.c=.o)



NAME		= fractol
BONUS_NAME	= fractol_bonus

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS) 
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLX_FLAGS)  -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) 
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $(BONUS_NAME)

./source/Mandatory/%.o: ./source/Mandatory/%.c ./source/Mandatory/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

./source/Bonus/%.o: ./source/Bonus/%.c ./source/Bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
re: fclean all

.PHONY: all clean fclean re bonus
