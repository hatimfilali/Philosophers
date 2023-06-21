#include "philo.h"


long	ft_timestamps(long time)
{
	struct timeval current;
	long	current_time;
	gettimeofday(&current, NULL);
	current_time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (current_time - time);
}
