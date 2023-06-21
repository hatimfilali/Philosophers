#include "philo.h"


int check_all_ate(int *tab, int size)
{
	int i;

	i = 0;
	while (i <size && tab[i] == 1)
		i++;
	if (i == size)
		return (1);
	return (0);
}