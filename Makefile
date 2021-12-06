# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shavok <shavok@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 12:27:56 by shavok            #+#    #+#              #
#    Updated: 2021/12/06 14:27:10 by shavok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	

HEADER	=	push_swap.h
OBJ		=	$(SRCS:%.c=%.o)
OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)	

$(NAME)	:	$(OBJ)	$(HEADER)
			ar rc $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	:	
	make OBJ='$(OBJ_B)' all

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all