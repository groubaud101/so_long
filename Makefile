# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:34:29 by user42            #+#    #+#              #
#    Updated: 2021/09/07 12:40:25 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

DIR_FT	=	./libft
DIR_MLX	=	./minilibx-linux
DIR_S	=	./

LIBFT	=	-L $(DIR_FT) -lft
LIBMLX	=	-L $(DIR_MLX) -lmlx -lXext -lX11
LIB		=	$(LIBFT) $(LIBMLX)

I_INC	=	-I $(DIR_FT)/include -I. -I $(DIR_MLX)

INC_L	=	$(DIR_L)/include/
INC_LIB	=	printf get_next_line libft
INCLUDE	=	$(DIR_MLX) $(addprefix $(INC_L), $(addsuffix .h, $(H_INC))) ft_$(NAME).h

SRC		=	init_map free_list_map create_lstmap check

OBJS	=	main.o $(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SRC)))

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

all		:	$(NAME)

%.o		:	%.c $(INCLUDE)
			$(CC) $(CFLAGS) $(I_INC) -c -o $@ $<
	
lib		:
			make -C $(DIR_FT)
			make -C $(DIR_MLX)

$(NAME)	:	$(OBJS) $(INCLUDE)
#			make lib
			$(CC) $(CFLAGS) $(I_INC) $(OBJS) $(LIB) -o $(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)
			make -C $(DIR_FT) fclean

re		:	fclean all

.PHONY	:	all clean fclean re