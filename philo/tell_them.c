/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell_them.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:33 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/22 23:15:54 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	tell_them(char *str, int id, long time, t_variables *var)
{
	time = ft_timestamps(0) - var->time_start;
	pthread_mutex_lock(var->writing);
	pthread_mutex_lock(var->general);
	if (*(var->flag))
	{
		pthread_mutex_unlock(var->writing);
		pthread_mutex_unlock(var->general);
		return ;
	}
	pthread_mutex_unlock(var->general);
	printf("%ld PHILO %d %s", time, id, str);
	pthread_mutex_unlock(var->writing);
}
