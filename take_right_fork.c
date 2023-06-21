#include "philo.h"


int take_rfork(t_variables *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->general);
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	return (0);
}