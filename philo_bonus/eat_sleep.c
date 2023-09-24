/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 07:11:46 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 18:33:39 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(long long msec)
{
	long long	start;

	start = ft_timestamps();
	while (ft_timestamps() - start < msec)
		usleep(msec / 10);
}

void	philo_eat(t_variables *philo)
{
	sem_wait(philo->cmn_data->forks);
	tell_them(philo, "HAS TAKEN A FORK");
	sem_wait(philo->cmn_data->forks);
	tell_them(philo, "HAS TAKEN A FORK");
	sem_wait(philo->cmn_data->eating);
	tell_them(philo, "IS EATING");
	philo->last_meal = ft_timestamps();
	philo->n_eat++;
	sem_post(philo->cmn_data->eating);
	ft_usleep(philo->cmn_data->life.eat);
	sem_post(philo->cmn_data->forks);
	sem_post(philo->cmn_data->forks);
}

void	philo_sleep(t_variables *philo)
{
	tell_them(philo, "IS SLEEPING");
	ft_usleep(philo->cmn_data->life.sleep);
}
