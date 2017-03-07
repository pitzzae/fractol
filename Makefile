#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 16:40:23 by gtorresa          #+#    #+#              #
#*   Updated: 2016/02/11 16:49:11 by gtorresa         ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME = fractol

LIB_DIR = ./libft
LIB_MLX_DIR = ./minilibx

LIB_NAME = $(LIB_DIR)/libft.a

CFLAGS=-Wall -Wextra -Werror

SRCS_DIR = ./srcs/

SRCS = $(SRCS_DIR)main.c
SRCS += $(SRCS_DIR)init_x11.c
SRCS += $(SRCS_DIR)action.c
SRCS += $(SRCS_DIR)screen.c
SRCS += $(SRCS_DIR)thread.c
SRCS += $(SRCS_DIR)init_fractal_julia.c
SRCS += $(SRCS_DIR)init_fractal_mandelbrot.c
SRCS += $(SRCS_DIR)fractal.c
SRCS += $(SRCS_DIR)ft_complexe.c

#MINILIBX = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = -L./mlx -lmlx -lXext -lX11 -lm -lpthread -lOpenCL

all: ${NAME}

$(NAME):
	@echo "Make lib_ft"
	@make -C $(LIB_DIR)
	@echo "Make $(NAME)"
	@gcc -o $(NAME) $(SRCS) -I./includes -L$(LIB_DIR) -lft $(MINILIBX)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete $(NAME)"

clean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(LIB_NAME)
	@echo "Delete $(LIB_NAME)"
	@make -C $(LIB_MLX_DIR) clean
	@echo "Delete $(LIB_MLX_DIR)"

re: fclean all
