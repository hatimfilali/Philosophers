#include "philo.h"


int ft_usleep(int time)
{
	long long start;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
