CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= push_swap
OBJ= push_swap.c check.c ft_atoi.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_split.c ft_substr.c ft_strlen.c rules.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c sort_a.c
OBJ_O= $(OBJ:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $(NAME)


clean:
	rm -rf $(OBJ_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ_O)

