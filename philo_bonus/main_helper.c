/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:32:45 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 18:49:42 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_variables	*philo;

	philo = (t_variables *)arg;
	while (1)
	{
		sem_wait(philo->cmn_data->eating);
		if (philo->cmn_data->life.max_meals != -1
			&& philo->n_eat == philo->cmn_data->life.max_meals)
		{
			sem_post(philo->cmn_data->eating);
			break ;
		}
		if (ft_timestamps() - philo->last_meal
			>= (long long)philo->cmn_data->life.die)
		{
			sem_wait(philo->cmn_data->writing);
			printf("%lld PHILO %d DIED\n", ft_timestamps(), philo->id);
			exit (1);
		}
		sem_post(philo->cmn_data->eating);
		usleep(100);
	}
	return (NULL);
}

void	philosopher(t_variables *var)
{
	pthread_t	philo_thread;

	if (var->id % 2 == 0)
		usleep(100);
	pthread_create(&philo_thread, NULL, routine, var);
	while (1)
	{
		philo_eat(var);
		if (var->cmn_data->life.max_meals != -1
			&& var->n_eat >= var->cmn_data->life.max_meals)
			break ;
		philo_sleep(var);
		tell_them(var, "IS THINKING");
	}
	pthread_join(philo_thread, NULL);
	exit(0);
}

void	philos_bonus(t_philos *philos)
{
	int	i;

	i = 0;
	ft_timestamps();
	while (i < philos->life.philo_number)
	{
		philos->philo_var[i].id = i + 1;
		philos->philo_var[i].n_eat = 0;
		philos->philo_var[i].cmn_data = philos;
		philos->philo_var[i].last_meal = ft_timestamps();
		philos->philo_var[i].pid = fork();
		if (philos->philo_var[i].pid == 0)
			philosopher(&philos->philo_var[i]);
		i++;
	}
}
