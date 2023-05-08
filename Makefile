# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatki <aatki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 22:47:05 by houaslam          #+#    #+#              #
#    Updated: 2023/05/08 18:16:56 by aatki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

LIBFT = ./libft/ft_atoi.c \
		./libft/ft_bzero.c \
		./libft/ft_calloc.c \
		./libft/ft_isalnum.c \
		./libft/ft_isalpha.c \
		./libft/ft_isascii.c \
		./libft/ft_isdigit.c \
		./libft/ft_isprint.c \
		./libft/ft_itoa.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_memcpy.c \
		./libft/ft_memmove.c \
		./libft/ft_memset.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_split.c \
		./libft/ft_strchr.c \
		./libft/ft_strdup.c \
		./libft/ft_striteri.c \
		./libft/ft_strjoin.c \
		./libft/ft_strjoin_free.c \
		./libft/ft_strlcat.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strlen.c \
		./libft/ft_strmapi.c \
		./libft/ft_strncmp.c \
		./libft/ft_strnstr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strtrim.c \
		./libft/ft_substr.c \
		./libft/ft_tolower.c \
		./libft/ft_toupper.c \
		./libft/ft_strcmp.c \
		./libft/ft_strcpy.c

BUILTINS =  ./executionn/builtins/utils.c\
			./executionn/builtins/cd.c\
			./executionn/builtins/echo.c\
			./executionn/builtins/env.c\
			./executionn/builtins/exit.c\
			./executionn/builtins/export.c\
			./executionn/builtins/pwd.c\
			./executionn/builtins/unset.c\
			./executionn/builtins/export_utils.c

PIPEX =./executionn/pipex/pipex_bonus.c\
		./executionn/pipex/pipex_utils_bonus.c\
		./executionn/pipex/ft_split_bonus.c\
		./executionn/pipex/here_doc.c\
		./executionn/pipex/get_next_line.c\
		./executionn/pipex/get_next_line_utils.c\
		./executionn/pipex/open_files.c

SRC =   global/main.c \
		global/transmetter.c \
		./parsing/libft_bonus/env_linked_list.c \
		./parsing/libft_bonus/exec_linked_list.c \
		./parsing/libft_bonus/file_linked_list.c \
		./parsing/lexer/tokens_string.c \
		./parsing/lexer/tokens_spec_char.c \
		./parsing/lexer/outils.c \
		./parsing/lexer/lexer.c \
		./parsing/lexer/ft_isstring.c

SRCS= ${SRC} ${PIPEX} ${BUILTINS} ${LIBFT}

all : ${NAME}

OBJ = ${SRCS:.c=.o}
B_OBJ = ${B_SRCS:.c=.o}

${NAME} : ${SRCS}
	cc $(CFLAGS) ${SRCS} -o ${NAME}  -L/usr/local/lib -lreadline

clean :
	rm -f ${OBJ}

push :
	git add .
	git commit -m minishell
	git push origin master

fclean : clean
	rm -f $(NAME)

re: fclean all
