#include "philo.h"


void 	philo_dead(t_variables *var, int *finished, int inedx)
{
	*finished = 1;
	pthread_mutex_lock(var->general);
	*(var->flag) = 1;
	pthread_mutex_unlock(var->general);
	pthread_mutex_lock(var->writing);
	printf("%ld PHILO NUMBER %d DIED\n", ft_timestamps(0) - var->last_meal, inedx + 1);
	pthread_mutex_unlock(var->writing);
	pthread_mutex_unlock(var->eating);
}
