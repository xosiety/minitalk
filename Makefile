# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 12:13:50 by afabbri           #+#    #+#              #
#    Updated: 2023/05/23 16:10:16 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMEC = client
NAMES = server
LIBFT = libft.a
PRINTF = libftprintf.a
SRCC_FILES = client.c
SRCS_FILES = server.c
SRC_DIR = source/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C libft
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) libft/$(LIBFT) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) libft/$(LIBFT) -o $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)


clean :
		@make clean -C printf
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		@make fclean -C printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all clean fclean re
