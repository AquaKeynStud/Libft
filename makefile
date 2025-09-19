.PHONY : all clean fclean re bonus norminette

.DELETE_ON_ERROR:

NAME := libft.a

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC				:=	cc

AR				:=	ar rcs

CFLAGS			:= -Wall -Wextra -Werror -MMD -g3

RM				:=	rm -rf

MKDIR			:=	mkdir -p

SHOW_MSG_CLEAN	=	true

MAKEFLAGS		+=	--no-print-directory

RESET			:=	\e[0m
BOLD			:=	\e[1m
RED				:=	\e[31m
BLUE			:=	\e[34m
GREEN			:=	\e[32m
YELLOW			:=	\e[33m
PURPLE			:=	\e[35m
CYAN			:=	\e[96m

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_INC	=	inc/
D_GNL	=	gnl/
D_SRC	=	srcs/
D_BON	=	bonus/
D_BLD	=	.build/
D_PTF	=	printf/
D_UPG	=	upgrade/

D_OBJ	=	$(D_BLD)obj/
D_DEP	=	$(D_BLD)dep/

D_SRCS	=	$(D_INC) $(D_SRC) $(D_BON) $(D_PTF) $(D_GNL) $(D_UPG)

# sources
LST_SRC =	ft_atoi.c		\
			ft_itoa.c		\
			ft_bzero.c		\
			ft_split.c		\
			ft_calloc.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memset.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strlen.c		\
			ft_substr.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memmove.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_striteri.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c

LST_BON	=	ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstsize.c		\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstadd_back.c	\
			ft_lstadd_front.c

LST_PTF	=	main.c					\
			utils.c					\
			handlers.c				\
			printers.c				\
			bonus_utils.c			\
			bonus_parser.c			\
			bonus_setter.c			\
			dprintf_main.c			\
			dprintf_handlers.c		\
			bonus_printers_diuc.c	\
			bonus_printers_spxX.c	\
			bonus_error_handler.c

LST_GNL	=	get_next_line.c			\
			get_next_line_utils.c

LST_UPG	=	in_str.c				\
			ft_trim.c				\
			ft_atoll.c				\
			get_word.c				\
			split_str.c				\
			ft_isspace.c			\
			ft_realloc.c			\
			double_free.c			\
			is_empty_line.c

LST_INC	=	libft.h					\
			upgrade.h				\
			ft_printf.h				\
			get_next_line.h

LST_SRCS	=	$(LST_SRC) $(LST_UPG) $(LST_PTF) $(LST_GNL)
LST_BONS	=	$(LST_SRC) $(LST_UPG) $(LST_PTF) $(LST_GNL) $(LST_BON)

INC			=	$(addprefix $(D_INC), $(LST_INC))

OBJ			=	$(addprefix $(D_OBJ), $(notdir $(LST_SRCS:.c=.o)))

BOBJ		=	$(addprefix $(D_OBJ), $(notdir $(LST_BON:.c=.o)))

DEPS		=	$(addprefix $(D_DEP), $(notdir $(LST_SRCS:.c=.d)))

BDEPS		=	$(addprefix $(D_DEP), $(notdir $(LST_BON:.c=.d)))

INCS		=	-I$(D_INC)

ifeq ($(MAKECMDGOALS),bonus)
TOTAL_FILES := $(words $(LST_BONS))
else
TOTAL_FILES := $(words $(LST_SRCS))
endif

START_TIME	:=	$(shell date +%s%3N)

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all: $(NAME)

$(NAME): $(OBJ) $(INC) makefile | $(D_BLD) $(D_OBJ) $(D_DEP) makefile
	@$(AR) $@ $?
	@END_TIME=$$(date +%s%3N);						\
	ELAPSED=$$(expr $$END_TIME - $(START_TIME));		\
	ELAPSED_SEC=$$(echo "scale=2; $$ELAPSED / 1000" | bc);	\
	printf "$(PURPLE)$(BOLD)\n🪼 $(NAME) created successfully in %0.2fs 🪼$(RESET)\n" $$ELAPSED_SEC

bonus: $(D_BLD)bonus

$(D_BLD)bonus: $(OBJ) $(BOBJ) makefile | $(D_BLD) $(D_OBJ) $(D_DEP) makefile
	@$(AR) $(NAME) $?
	@touch $(D_BLD)bonus
	@END_TIME=$$(date +%s%3N);						\
	ELAPSED=$$(expr $$END_TIME - $(START_TIME));		\
	ELAPSED_SEC=$$(echo "scale=2; $$ELAPSED / 1000" | bc);	\
	printf "$(PURPLE)$(BOLD)\n🪼 $(NAME) created successfully with bonuses in %0.2fs 🪼$(RESET)\n" $$ELAPSED_SEC

$(D_BLD):
	@$(MKDIR) $@

$(D_OBJ): $(D_BLD)
	@$(MKDIR) $@

$(D_DEP): $(D_BLD)
	@$(MKDIR) $@

$(D_OBJ)%.o: %.c $(INC) | $(D_OBJ) $(D_DEP) makefile
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ -MF $(D_DEP)$(notdir $*.d)
	@COMPILED=$$(ls $(D_OBJ)*.o 2>/dev/null | wc -w || false);	\
	PCT=$$((COMPILED * 100 / $(TOTAL_FILES)));					\
	printf "$(BOLD)[%3d%%] $(BLUE)🫧 $< binary file created 🫧$(RESET)\n" $$PCT

-include $(DEPS)
vpath %.c $(D_SRC) $(D_BON) $(D_PTF) $(D_GNL) $(D_UPG)

clean :
ifeq ($(SHOW_MSG_CLEAN), true)
	@echo "$(GREEN)$(BOLD)🍃 $(NAME) build files suppressed 🍃$(RESET)"
endif
	@$(RM) $(D_BLD)

fclean :
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(BOLD)🎐 $(NAME) completely removed 🎐$(RESET)"

re : 
	@$(MAKE) fclean
	@$(MAKE) all
