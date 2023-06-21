#include "philo.h"

int sleep_or_think(t_variables *philo)
{
	tell_them("IS SLEEPING\n", philo->id, ft_timestamps(philo->time_start), philo);
	ft_usleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->general);
	if (*(philo->flag))
	{
		pthread_mutex_unlock(philo->general);
		return (-1);
	}
	pthread_mutex_unlock(philo->general);
	tell_them("IS THINKING\n", philo->id, ft_timestamps(philo->time_start), philo);
	return (0);
}