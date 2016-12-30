# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sly <sly@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 18:35:31 by sly               #+#    #+#              #
#    Updated: 2016/12/30 00:58:34 by sly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC_PATH = ./src/
SRC_NAME = $(shell ls $(SRC_PATH) | grep "\.c")
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIBFT_PATH = ./libft/
LIBFT_NAME = -lft
MINILIBX_PATH = ./minilibx_macos/
MINILIBX_NAME = -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
AR = ar rc
CC = cc
CFLAGS += -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBDIR = -L
INC = $(addprefix -I , $(INC_PATH))

all: $(LIBFT_NAME) $(MINILIBX_NAME) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBDIR) $(LIBFT_PATH) $(LIBFT_NAME) $(LIBDIR) $(MINILIBX_PATH) $(MINILIBX_NAME) $(INC) -o $(NAME) $(OBJ) $(FRAMEWORK)

$(MINILIBX_NAME):
	@make -C $(MINILIBX_PATH)

minilibxclean:
	@make -C $(MINILIBX_PATH) clean

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)
	@make clean -C $(LIBFT_PATH)

libftclean:
	@make -C $(LIBFT_PATH) fclean

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean libftclean minilibxclean
	@rm -fv $(NAME)

re: fclean
	@make

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: clean $(LIBFT_NAME) fclean all re norme libftclean minilibxclean
