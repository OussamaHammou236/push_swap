CC= cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address
NAME= push_swap
BNAME= checker
OBJ= push_swap.c check.c ft_atoi.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_split.c ft_substr.c ft_strlen.c rules.c rules_2.c \
	rules_3.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c sort_a.c push_swap_utilis.c 
BOBJ= bonus/checker.c  bonus/ft_strncmp.c  bonus/get_next_line_utils.c  bonus/get_next_line.c check.c ft_atoi.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c \
	ft_lstlast_bonus.c ft_split.c ft_substr.c ft_strlen.c rules.c rules_2.c rules_3.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c sort_a.c push_swap_utilis.c
BOBJ_O= $(BOBJ:.c=.o)
OBJ_O= $(OBJ:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJ_O)
	$(CC) $(CFLAGS) $(BOBJ_O) -o $(BNAME)

clean:
	rm -rf $(OBJ_O) $(BOBJ_O)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all

.PHONY: clean

.SECONDARY: $(OBJ_O) $(BOBJ_O)
