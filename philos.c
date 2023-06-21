#include "philo.h"

void init_philos(t_arguments *num, t_variables *var)
{
	int i = 0;
	num->eating = malloc (sizeof(pthread_mutex_t));
	num->writing = malloc (sizeof(pthread_mutex_t));
	num->general = malloc (sizeof(pthread_mutex_t));
	num->fork = malloc (sizeof(pthread_mutex_t));
	num->flg = malloc(sizeof(int));
	*(num->flg) = 0;
	num->time = ft_timestamps(0);
	pthread_mutex_init(num->eating, NULL);
	pthread_mutex_init(num->writing, NULL);
	pthread_mutex_init(num->general, NULL);
	while (i < num->philo_number)
	{
		var[i].id = i + 1;
		var[i].left_fork = &num->fork[i];
		var[i].right_fork = &num->fork[(i + 1) % num->philo_number];
		var[i].last_meal = ft_timestamps(0);
		var[i].eating = num->eating;
		var[i].writing = num->writing;
		var[i].general = num->general;
		var[i].time_start = ft_timestamps(0);
		var[i].max_meals = 0;
		var[i].flag = num->flg;
		var[i].time_to_eat = num->time_to_eat;
		var[i].time_to_sleep = num->time_to_sleep;
		pthread_mutex_init(&num->fork[i], NULL);
		i++;
	}
}

void creat_threads(t_arguments num, t_variables *var)
{
	int j = 0;
	int result;
	while (j < num.philo_number)
	{
		result  = pthread_create(&var[j].philo_threads, NULL, routine, &var[j]);
		if (result)
			ft_error();
		usleep(50);
		j++;

	}
}

void creat_philos(t_variables *var, t_arguments *num)
{
	int k = 0;
	var->fin = 0;
	while (var->fin == 0)
	{
		k = 0;
		while (k<num->philo_number)
		{
			if(philo_check(&var[k], num, k) == -1)
				return;
			k++;
		}
		philo_check_helper(var, &var->fin, num);
	}
}

void	philos(t_arguments *num)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * num->philo_number);
	if (!var)
	{
		ft_error();
		return;
	}
	init_philos(num, var);
	creat_threads(*num, var);
	creat_philos(var, num);
	if (num->philo_number != 1)
	{
		int i = 0;
		while (i < num->philo_number)
		{
			pthread_join(var[i].philo_threads, NULL);
			i++;
		}
	}
}
