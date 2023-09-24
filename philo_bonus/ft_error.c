/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:24:30 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 00:09:29 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(int i)
{
	if (i == 0)
		printf("Error\n");
	if (i == 1)
		printf("Error in arguments\n");
	if (i == 2)
		printf("Error in threads\n");
	if (i == 3)
		printf("Error in semaphores\n");
}
