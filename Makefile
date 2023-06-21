
NAME = philo

SRC = main.c eat.c ft_timestamps.c philo_check.c routine.c take_right_fork.c arguments_parsing.c ft_atoi.c ft_usleep.c max_meals_check.c philo_dead.c sleep_or_think.c tell_them.c check_all_ate.c ft_error.c get_time.c philos.c take_left_fork.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3

RM = rm -rf

all: $(NAME)
$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "PHILO IS READY TO BE EXECUTED ✅✅"

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@echo "OBJECTS DELETED 🚮🚮"
fclean : clean 
	@$(RM) $(NAME)
	@echo "PHILO DELETED 🚮🚮"
re : fclean all