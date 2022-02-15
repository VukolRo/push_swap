# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shavok <shavok@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 14:06:30 by shavok            #+#    #+#              #
#    Updated: 2022/02/15 21:14:36 by shavok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	=	checker

SRCS	=	push_swap.c		parsing_args.c		ft_atoi_long.c \
			fill_stack.c	node_add.c			hard_sort.c \
			easy_sort.c		push_five_between.c	find_for_hard.c \
			ops_push.c		ops_swap.c			ops_rotation.c

# SRCS_B	=	cheker.c	

OBJ		=	$(SRCS:%.c=%.o)

# OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n\t Complited $(NAME) \n$(END)"

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@

# bonus:		libft $(OBJ_B)
# 			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
# 			@echo "$(TURQUOISE)\n\tComplited $(NAME_B) \n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\n\tCleaning succeed\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\tAll files were deleted\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"