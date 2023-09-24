/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:42:48 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 00:09:41 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_timestamps(void)
{
	static long long	start;
	struct timeval		tv;
	long long			m_sec;

	if (gettimeofday(&tv, NULL))
		printf("Error getting the time\n");
	m_sec = tv.tv_sec * 1000;
	m_sec += tv.tv_usec / 1000;
	if (!start)
		start = m_sec;
	return (m_sec - start);
}
