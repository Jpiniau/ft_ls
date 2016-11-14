# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 15:51:57 by jpiniau           #+#    #+#              #
#    Updated: 2016/11/14 17:23:10 by jpiniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_ls

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

SRC_NAME =	main.c\
			is_dir.c\
			get_perm.c\
			get_uid.c\
			get_gid.c\
			get_size.c\
			get_mod.c\
			get_link.c\
			recursive.c\
			set_info.c\
			print_ls.c\
			del_ls.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: lib $(NAME)

lib:
	@make -C libft/

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $@ $^ -L libft/ -lft

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -o $@ -c $< -I libft/includes -I includes/.

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all
