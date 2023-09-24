/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_left_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:28 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/24 10:16:23 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_lfork(t_variables *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->general);
	pthread_mutex_unlock(philo->general);
	tell_them("HAS TAKEN LEFT FORK\n", philo->id,
		ft_timestamps(philo->time_start), philo);
}
