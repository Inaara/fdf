# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 04:40:22 by pszleper          #+#    #+#              #
#    Updated: 2022/08/16 21:46:34 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

AR = ar -rcs

FLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

SRC	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c			\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c		\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c		\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c			\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c		\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c				\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c			\
		ft_lstmap.c ft_is_space.c \
		$(GNL_SRC) $(FT_PRINTF_SRC)

OBJECTS = $(SRC:.c=.o)

GNL_DIR = get_next_line/

GNL_SRC = $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

FT_PRINTF_DIR = ft_printf/

FT_PRINTF_SRC = $(addprefix $(FT_PRINTF_DIR), ft_converters.c 		\
				ft_numconverters.c ft_printf.c ft_putpointer.c 	\
				ft_strutil.c)

HEADERS =	libft.h

all: echo_compiling_libft $(NAME)

echo_compiling_libft:
	@echo "Compiling Libft..."

$(NAME): echo_compiling_libft $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS) $(HEADERS)
	@echo "Libft compiled!"

%.o: %.c
	@$(CC) $(FLAGS) $< -o $@

.PHONY: all clean fclean re echo_compiling_libft

clean:
	@rm -f *.o
	@rm -f $(addprefix $(GNL_DIR), *.o)
	@rm -f $(addprefix $(FT_PRINTF_DIR), *.o)
	@echo "Cleaned the repo"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed libft.a"

re: fclean all