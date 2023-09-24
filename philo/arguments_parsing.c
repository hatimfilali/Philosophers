/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:41:14 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/22 22:43:12 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arguments_parsing(int arc, char **arv, t_arguments *num)
{
	num->philo_number = ft_atoi(arv[1]);
	num->time_to_die = ft_atoi(arv[2]);
	num->time_to_eat = ft_atoi(arv[3]);
	num->time_to_sleep = ft_atoi(arv[4]);
	num->max_meals = -1;
	num->all_ate = NULL;
	if (num->philo_number <= 0 || num->time_to_die <= 0
		|| num->time_to_eat <= 0 || num->time_to_sleep <= 0)
	{
		ft_error();
		return (1);
	}
	if (max_meals_check(arc, arv, num) == 1)
		return (1);
	return (0);
}
