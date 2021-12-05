# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 15:34:29 by user42            #+#    #+#              #
#    Updated: 2021/12/05 15:06:18 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

DIR_FT	=	./lib/libft/
DIR_MLX	=	./lib/minilibx/
D_INC_L	=	$(DIR_FT)/include/
D_INC	=	./includes/

D_BACK	=	./dir_back/
D_FRONT	=	./dir_front/

LIBFT	=	-L $(DIR_FT) -lft
LIBMLX	=	-L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
LIB		=	$(LIBFT) $(LIBMLX)

INC_LIB	=	ft_printf get_next_line libft
INCS	=	mlx ft_$(NAME) ft_colors 
INCLUDE	=	$(addprefix $(D_INC_L), $(addsuffix .h, $(INC_LIB))) \
			$(addprefix $(D_INC), $(addsuffix .h, $(INCS)))

I_INC	=	-I $(D_INC_L) -I $(D_INC)

S_BACK	=	init_map free_list_map create_lstmap check map_err_msg \
			define_data_ptr
S_FRONT	=	so_long foreground_layer geometric_figure mlx_pixel_put \
			texture_wall texture_floor texture_exit texture_collectible \
			movement_player move close set_norm_value
SRCS	=	$(addprefix $(D_BACK)ft_, $(addsuffix .c, $(S_BACK))) \
			$(addprefix $(D_FRONT)ft_, $(addsuffix .c, $(S_FRONT)))

OBJS	=	main.o $(addprefix $(D_BACK)ft_, $(addsuffix .o, $(S_BACK))) \
			$(addprefix $(D_FRONT)ft_, $(addsuffix .o, $(S_FRONT)))

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

all		:	$(NAME)

%.o		:	%.c $(INCLUDE)
			$(CC) $(CFLAGS) $(I_INC) -c -o $@ $<

lib		:
			make -C $(DIR_FT)
			make -C $(DIR_MLX)
			cp $(DIR_MLX)libmlx.dylib .

$(NAME)	:	$(OBJS) $(INCLUDE)
			make lib
			$(CC) $(CFLAGS) $(I_INC) $(OBJS) $(LIB) -o $(NAME)

clean	:
			rm -rf $(OBJS)
#			make -C $(DIR_FT) clean
#			make -C $(DIR_MLX) clean

fclean	:	clean
			rm -f $(NAME)
			rm -f libmlx.dylib
			make -C $(DIR_FT) fclean

re		:	fclean all

.PHONY	:	all clean fclean re lib