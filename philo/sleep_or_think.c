/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_or_think.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:26 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/23 15:46:44 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_or_think(t_variables *philo)
{
	tell_them("IS SLEEPING\n", philo->id,
		ft_timestamps(philo->time_start), philo);
	ft_usleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->general);
	if (*(philo->flag))
	{
		pthread_mutex_unlock(philo->general);
		return (-1);
	}
	pthread_mutex_unlock(philo->general);
	tell_them("IS THINKING\n", philo->id,
		ft_timestamps(philo->time_start), philo);
	return (0);
}
