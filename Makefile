# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:51:05 by yakdik            #+#    #+#              #
#    Updated: 2023/10/18 21:53:55 by yakdik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH	= library/libft

NAME		= so_long
HEADER		= includes/so_long.h
BONUSNAME	= so_long_bonus
GREEN='\033[0;32'
NC='\033[0m'

MINILIBX	= library/minilibx_opengl/


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo

OPENGL		= -framework OpenGL -framework AppKit

MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx


COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a $(MINILIBX)/libmlx.a
COMPILEPRMB	= $(MINILIBXCC) $(OPENGL) -o $(BONUSNAME) libft.a $(MINILIBX)/libmlx.a
MANDATORYFILES = sources/mandatory/checks.c \
 				sources/mandatory/draw.c \
 				sources/mandatory/initiliazers.c \
 				sources/mandatory/move.c \
 				sources/mandatory/path_finding.c \
 				sources/mandatory/render.c \
 				sources/mandatory/so_long.c \
 				sources/mandatory/utilities_error.c \
 				sources/mandatory/utilities_extra.c \
 				sources/mandatory/utilities_game.c \
 				sources/mandatory/utilities_map.c

BONUSFILES = 	 sources/bonus/bonus_checks.c \
				sources/bonus/bonus_draw.c \
				sources/bonus/bonus_move.c \
				sources/bonus/bonus_path_finding.c \
				sources/bonus/bonus_render.c \
				sources/bonus/bonus_so_long.c \
				sources/bonus/bonus_utilities_error.c \
				sources/bonus/bonus_utilities_extra.c \
				sources/bonus/bonus_utilities_game.c \
				sources/bonus/bonus_utilities_map.c \
				sources/bonus/bonus_initiliazers.c \
				sources/bonus/bonus_utilities.c
			
MANDATORYOBJ	=	$(MANDATORYFILES:.c=.o)
BONUSOBJ		=	$(BONUSFILES:.c=.o)
start:
			@make all
all:		$(NAME)
$(NAME):	$(MANDATORYFILES)
			@echo "Minilibx library is compiling..."
			@make -s -C $(MINILIBX) 2> /dev/null
			@echo "================================"
			@echo "Libft library is compiling..."
			@make -C $(LIBFTPATH) 2> /dev/null
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(MANDATORYFILES) $(COMPILEPRM)
			@echo "================================"
			@echo "DONE!"
bonus:		$(BONUSFILES)
			@echo "Minilibx library is compiling..."
			@make -s -C $(MINILIBX) 2> /dev/null
			@echo "================================"
			@echo "Libft library is compiling..."
			@make -C $(LIBFTPATH) 2> /dev/null
			@cp $(LIBFTPATH)/libft.a . 
			@$(CC) $(CFLAGS) $(BONUSFILES) $(COMPILEPRMB)
			@echo "================================"
			@echo "DONE!"
clean:
			@$(RM) -r $(MANDATORYOBJ) 2> /dev/null
			@$(RM) -r $(BONUSOBJ) 2> /dev/null
			@make clean -C $(MINILIBX) 2> /dev/null
			@make clean -C $(LIBFTPATH) 2> /dev/null
fclean:		clean
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -r $(NAME)
			@$(RM) -r $(BONUSNAME)
			@$(RM) -rf libft.a
re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"
.PHONY:		all clean fclean re norm