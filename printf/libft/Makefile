# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 10:50:58 by afabbri           #+#    #+#              #
#    Updated: 2023/02/12 12:07:29 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_substr.c ft_strlen.c ft_strchr.c ft_strdup.c ft_strtrim.c ft_striteri.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_split.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strnstr.c ft_strrchr.c ft_strmapi.c ft_tolower.c ft_toupper.c  \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
ft_atoi.c ft_bzero.c ft_calloc.c \

OBJ = ${SRCS:.c=.o}

BONUS = ft_lstnew.c ft_lstsize.c ft_lstlast.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c  ft_lstmap.c \
ft_lstadd_back.c ft_lstadd_front.c \

BNS = ${BONUS:.c=.o}

${NAME} : ${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@echo "library created"

bonus: ${BNS}
	@ar rcs ${NAME} ${BNS}
	@echo "Bonus added"

%.o : %.c
	@gcc ${FLAG} $< -c

clean:
	@rm -f ${OBJ} ${BNS}
	@echo "objects deleted"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted"

all: ${NAME}

re: fclean all
