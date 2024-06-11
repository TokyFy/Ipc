# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franaivo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:07:39 by franaivo          #+#    #+#              #
#    Updated: 2024/02/21 10:07:39 by franaivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
					ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
					ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
					ft_calloc.c ft_strdup.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
					ft_itoa.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c 

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

OBJECTS = $(SOURCES:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : %.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@

$(OBJ_BONUS) : %.o : %.c
	@$(CC) -c $(FLAGS) $< -o $@

bonus : $(OBJECTS) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJECTS) $(OBJ_BONUS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

lib : all clean

re : fclean all

