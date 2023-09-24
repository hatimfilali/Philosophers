/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_meals_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:09 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/22 22:49:56 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	max_meals_check(int arc, char **arv, t_arguments *num)
{
	if (arc == 6)
	{
		num->max_meals = ft_atoi(arv[5]);
		if (num->max_meals <= 0)
		{
			ft_error();
			return (1);
		}
		num->all_ate = malloc(sizeof(int) * num->philo_number);
		if (num->all_ate == NULL)
		{
			ft_error();
			return (1);
		}
	}
	return (0);
}
