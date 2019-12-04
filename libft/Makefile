# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arraji <arraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 13:57:03 by arraji            #+#    #+#              #
#    Updated: 2019/11/01 00:41:41 by arraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
SRC  = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_itoa.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lst_test.c \
		ft_lstpr_char_en.c \
		ft_lstpr_char.c 

BONUS_SRC = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

BONUS_OBJECT = $(BONUS_SRC:.c=.o)

HEADERS = ./
OBJECT = $(SRC:.c=.o)

.PHONY = all bonus clean fclean re
$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

bonus: all $(BONUS_OBJECT) 
	$(AR) $(NAME) $(BONUS_OBJECT)

%.o: %.c
	gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(BONUS_OBJECT) $(OBJECT)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

everthing: all bonus clean
