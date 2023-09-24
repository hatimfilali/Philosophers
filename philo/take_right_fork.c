/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_right_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:30 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/24 10:16:21 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_rfork(t_variables *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->general);
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	return (0);
}
