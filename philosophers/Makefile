NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=thread  -g

SRCS = main.c arg_control.c arg_atoi.c init_mutex.c init_philo.c \
		start_simulation.c time.c sequential_operations.c dead.c \
		write.c destroy.c free.c

OBJS = $(SRCS:.c=.o)

BLUE		:= \033[1;34m

all: $(NAME)
	@echo "$(BLUE)Compile Completed!"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re