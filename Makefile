# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arocca <arocca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:09:59 by arocca            #+#    #+#              #
#    Updated: 2024/11/19 15:47:43 by arocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
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
		ft_striteri.c \
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
		ft_tolower.c \
		ft_toupper.c \

BSRC =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \


OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

DEPS = $(OBJ:.o=.d)
BDEPS = $(BOBJ:.o=.d)

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(BOBJ)
	@if ar -t $(NAME) | grep -q -v -e "$(BOBJ)" && ar rcs $(NAME) $(BOBJ); then \
		echo "libft.a is up to date"; \
	fi

-include $(DEPS)
-include $(BDEPS)

clean :
	rm -f $(OBJ) $(BOBJ) $(DEPS) $(BDEPS)

fclean :
	$(MAKE) clean
	rm -f $(NAME)

re : 
	$(MAKE) fclean all