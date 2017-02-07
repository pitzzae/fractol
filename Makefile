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
O_DIR = ./obj
O_DIR_CUDA = ./obj_cuda
SRCS_DIR = ./srcs/

LIB_NAME = $(LIB_DIR)/libft.a

CFLAGS=-Wall -Wextra -Werror

SRCS 		= 	main.c init_x11.c action.c thread.c \
				init_fractal_julia.c init_fractal_mandelbrot.c \
				ft_complexe.c

SRCS_CUDA	= 	fractal.cu screen.cu

#MINILIBX = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = -L./mlx -lmlx -lXext -lX11 -lm -lpthread

OBJS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))
OBJS_CUDA = $(addprefix $(O_DIR_CUDA)/,$(SRCS_CUDA:.cu=.o))

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_CUDA)
	@echo "\nMake lib_ft"
	@make -C $(LIB_DIR)
	@echo "Make $(NAME)"
	@nvcc -arch=sm_20 -o $(NAME) -I./includes -L$(LIB_DIR) -lft $(MINILIBX) $(OBJS_CUDA) $(OBJS)


$(O_DIR)/%.o: ./$(SRCS_DIR)/%.c
	@mkdir -p $(O_DIR)
	@printf "."
	@gcc -c $< -I./includes -o $@

$(O_DIR_CUDA)/%.o: ./$(SRCS_DIR)/%.cu
	@mkdir -p $(O_DIR_CUDA)
	@printf "."
	@nvcc -c $< -I./includes -o $@

fclean: clean
	@rm -f $(NAME)
	@echo "Delete $(NAME)"

clean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(LIB_NAME)
	@echo "Delete $(LIB_NAME)"
	@make -C $(LIB_MLX_DIR) clean
	@echo "Delete $(LIB_MLX_DIR)"
	@rm -fr $(O_DIR)
	@rm -fr $(O_DIR_CUDA)

re: fclean all
