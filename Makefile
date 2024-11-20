# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arocca <arocca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 17:20:04 by arocca            #+#    #+#              #
#    Updated: 2024/11/20 18:56:39 by arocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus Makefile

NAME = libft.a

CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

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

OBJ_D = obj

$(shell mkdir -p $(OBJ_D))

OBJ = $(SRC:%.c=$(OBJ_D)/%.o)
BOBJ = $(BSRC:%.c=$(OBJ_D)/%.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?
	@echo "\e[0;32mArchive créée avec succès ! 🧬\e[0m"

$(OBJ_D)/%.o: %.c libft.h
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(BOBJ) $(DEPS) $(BDEPS)
	rm -r $(OBJ_D)
	@echo "\e[0;36mTout est nickel 🧹\e[0m"

fclean :
	$(MAKE) clean
	$(RM) $(NAME)
	$(RM) .bonus
	@echo "\e[0;34mJ'ai tout nettoyé :D 🧼\e[0m"

re : 
	$(MAKE) fclean all
	@echo "\e[0;32mArchive recréée avec succès ! 🫡\e[0m"

bonus: .bonus

.bonus : $(NAME) $(BOBJ)
	$(AR) $(NAME) $(BOBJ)
	touch .bonus
	@echo "\e[0;35mLes fichiers bonus ont bien étés ajoutés 📈\e[0m"