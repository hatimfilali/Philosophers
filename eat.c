#include "philo.h"


void	release_fork (t_variables *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int eat(t_variables *philo)
{
	pthread_mutex_unlock(philo->general);
	tell_them("HAS TAKEN RIGHT FORK\n", philo->id, ft_timestamps(philo->time_start), philo);
	pthread_mutex_lock(philo->eating);
	tell_them("IS EATING\n", philo->id,ft_timestamps(0), philo);
	philo->last_meal = ft_timestamps(0);
	philo->max_meals++;
	pthread_mutex_unlock(philo->eating);
	ft_usleep(philo->time_to_eat);
	release_fork(philo);
	return (0);
}