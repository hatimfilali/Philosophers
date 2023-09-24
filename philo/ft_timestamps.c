/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:41:57 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/24 07:49:09 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_timestamps(long time)
{
	struct timeval	current;
	long			current_time;

	gettimeofday(&current, NULL);
	current_time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (current_time - time);
}
