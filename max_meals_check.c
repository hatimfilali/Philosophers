#include "philo.h"


int max_meals_check(int arc, char** arv, t_arguments *num)
{
	if (arc == 6)
	{
		num->max_meals = ft_atoi(arv[5]);
		if (num->max_meals <= 0)
		{
			ft_error();
			return (1);
		}
		num->all_ate = malloc(sizeof(int) * num->philo_number);
		if (num->all_ate == NULL)
		{
			ft_error();
			return (1);
		}
	}
	return (0);
}