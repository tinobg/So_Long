# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 12:57:08 by brjoves           #+#    #+#              #
#    Updated: 2023/12/26 12:57:10 by brjoves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =    so_long

SRCS        =    main.c                            \
                get_next_line/get_next_line.c    \
                parsing/check_map.c                \
                parsing/load_map.c                 \
                parsing/parsing.c                \
                render/create_img.c                \
                render/keys.c                    \
                render/player_moves.c            \
                render/print_texture.c            \
                render/render.c                    \
                utils/free_and_errors.c            \
                utils/libft.c                    \
                utils/libft2.c

CC            =    cc

CFLAGS        =    -Wall -Wextra -Werror -g3

LFLAGS        =    libmlx.a libmlx_Linux.a -lX11 -lXext

OBJS        =    $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			make -C minilibx-linux/ && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ ./so_long successfully created! ~~"

clean:
			 make clean -C minilibx-linux/
			rm -rf $(OBJS)
			@echo "\033[31m ~~ ./so_long successfully deleted! ~~"

fclean: 		clean
			rm -rf $(NAME) libmlx.a libmlx_Linux.a
			@echo "\033[31m ~~ ./so_long successfully fdeleted! ~~"


re:            fclean all

.PHONY:        all clean fclean re
