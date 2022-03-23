# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 03:51:08 by pcottet           #+#    #+#              #
#    Updated: 2022/02/01 06:59:04 by pcottet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

CC			= gcc

LIBS		= libs/libft libs/minilibx_macos

FLAGS		= -Wall -Werror -Wextra

INCLUDES	= ./includes

SRCS_DIR	= ./srcs

SRCS_FILES	= fdf_key.c fdf_map.c fdf_map_utils.c fdf_trace_utils.c \
			fdf_trace_vectors.c fdf_trace.c fdf_utils.c \
			main.c fdf_key_arrows.c fdf_check_map.c

SRCS		= $(addprefix srcs/, ${SRCS_FILES})

OBJS		= $(SRCS:.c=.o)

LIBFT		= -L./libs/libft -lft

MLX			= -L./libs/minilibx -lmlx -framework OpenGL -framework AppKit

LIBS		= ${LIBFT} ${MLX}

all:	cclibft cclibmlx $(NAME)

$(NAME): ${OBJS}
		@echo "make Fdf"
		$(CC) $(FLAGS) ${OBJS} -o $@  $(LIBS)

%.o: %.c
		${CC} ${FLAGS} -o $@ -c $<

cclibft:
		@echo "make libft"
		@make -C./libs/libft/

cclibmlx:
		@echo "make minilibx"
		@make -C./libs/minilibx/

clean:
		/bin/rm -f $(OBJS)
		@make -C./libs/libft/ clean
		@make -C./libs/minilibx/ clean

fclean: clean
		/bin/rm -f $(NAME)
		@make -C./libs/libft/ fclean
		@make -C./libs/minilibx/ clean

re:		fclean all

norme:
		norminette ${SRCS}
		norminette ${INCLUDES}

.PHONY: all clean fclean re cclibmlx cclibft
