
NAME = philo_bonus

SRC = argument_parse.c eat_sleep.c ft_atoi.c ft_error.c ft_timestamp.c main_bonus.c tell_them.c main_helper.c kill_philos.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

all: $(NAME)
$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "PHILO_BONUS IS READY TO BE EXECUTED ✅✅"

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)
	@echo "BONUS OBJECTS DELETED 🚮🚮"
fclean : clean 
	@$(RM) $(NAME)
	@echo "PHILO_BONUS DELETED 🚮🚮"
re : fclean all