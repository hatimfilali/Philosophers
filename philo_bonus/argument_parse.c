/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:36:29 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 00:07:01 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	max_meals_check(int arc, char **arv, t_argumments *life)
{
	if (arc == 6)
	{
		life->max_meals = ft_atoi(arv[5]);
		if (life->max_meals <= 0)
		{
			ft_error(1);
			return (1);
		}
	}
	return (0);
}

int	arguments_parse(int arc, char **arv, t_argumments *life)
{
	life->philo_number = ft_atoi(arv[1]);
	life->die = ft_atoi(arv[2]);
	life->eat = ft_atoi(arv[3]);
	life->sleep = ft_atoi(arv[4]);
	life->max_meals = -1;
	if (life->philo_number <= 0 || life->die <= 0
		|| life->eat <= 0 || life->sleep <= 0)
	{
		ft_error(1);
		return (1);
	}
	if (max_meals_check(arc, arv, life) == 1)
		return (1);
	return (0);
}
