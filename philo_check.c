#include "philo.h"


void	philo_check_helper (t_variables *var, int *finished, t_arguments *args)
{
	if (args->max_meals != -1)
	{
		if (check_all_ate(args->all_ate, args->philo_number))
		{
			pthread_mutex_lock(var->general);
			*(var->flag) = 1;
			pthread_mutex_unlock(var->general);
			*finished = 1;
		}
	}
}

int philo_check(t_variables *philo, t_arguments *args, int index)
{
	pthread_mutex_lock(philo->eating);
	if (ft_timestamps(0) - philo->last_meal > args->time_to_die)
	{
		philo_dead(philo, &philo->fin, index);
		return (-1);
	}
	if (philo->max_meals == args->max_meals)
		args->all_ate[index] = 1;
		pthread_mutex_unlock(philo->eating);
		return (0);
}
