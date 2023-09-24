/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell_them.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:59:17 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 00:21:52 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	tell_them(t_variables *philo, char *str)
{
	sem_wait(philo->cmn_data->writing);
	printf("%lld PHILO %d %s\n", ft_timestamps(), philo->id, str);
	sem_post(philo->cmn_data->writing);
}
