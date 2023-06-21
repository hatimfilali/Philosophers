#include "philo.h"


void	*routine(void *arg)
{
	t_variables *philo;
	
	philo = (t_variables *)arg;
	while (1)
	{
		take_lfork(philo);
		if (take_rfork(philo) == -1)
			break;
		eat(philo);
		if (sleep_or_think(philo) == -1)
			break;
	}
	return (NULL);
}