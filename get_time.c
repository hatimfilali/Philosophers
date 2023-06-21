#include "philo.h"

long long	get_time(void)
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL))
		ft_error();
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / 1000));
}
