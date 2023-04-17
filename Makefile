# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 22:26:16 by aatki             #+#    #+#              #
#    Updated: 2023/04/17 00:39:38 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execution

BUILTINS = ./builtins/builtins.c\
			./builtins/builtins2.c\
			./builtins/utils.c\
			./builtins/heeelp.c

PIPEX =./pipex/pipex_bonus.c\
	./pipex/pipex_utils_bonus.c\
	./pipex/ft_split_bonus.c\
	./pipex/here_doc.c\
	./pipex/get_next_line.c\
	./pipex/get_next_line_utils.c\

OBJ1 = ${BUILTINIS:.c=.o}

OBJ2= ${PIPEX :.c=.o}

CFLAGS = #-Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${BUILTINS} ${PIPEX}
	gcc  ${CFLAGS} ./libfta/libft.a ${BUILTINS} ${PIPEX} -o ${NAME}

clean :
	rm -r ${OBJ}

fclean : clean
	rm -r ${NAME}

re : fclean all

git:
	git add . && git commit -m "hfghkf" && git push