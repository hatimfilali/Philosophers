#include "philo.h"


void	take_lfork (t_variables *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->general);
	pthread_mutex_unlock(philo->general);
	tell_them("HAS TAKEN LEFT FORK\n", philo->id, ft_timestamps(philo->time_start), philo);

}
