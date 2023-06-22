# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:51:05 by yakdik            #+#    #+#              #
#    Updated: 2023/04/19 13:13:24 by yakdik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH	= library/libft

NAME		= so_long
HEADER		= includes/so_long.h
BONUSNAME	= so_long_bonus
GREEN='\033[0;32'
NC='\033[0m'

# For MacOS
MINILIBX	= library/minilibx_opengl/


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo

# For MacOS
OPENGL		= -framework OpenGL -framework AppKit

# For MacOS
MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx


COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a $(MINILIBX)/libmlx.a
COMPILEPRMB	= $(MINILIBXCC) $(OPENGL) -o $(BONUSNAME) libft.a $(MINILIBX)/libmlx.a
MANDATORYFILES	= $(shell find sources -name "*.c" ! -name "bonus_so_long.c")
BONUSFILES		= $(shell find sources -name "*.c" ! -name "so_long.c")
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