/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:04:04 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 18:46:21 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	main_init(t_philos *philos)
{
	philos->forks = sem_open("forks", O_CREAT
			| O_EXCL, 0666, philos->life.philo_number);
	if (philos->forks == SEM_FAILED)
		ft_error(3);
	philos->philo_var = (t_variables *)malloc(sizeof(t_variables)
			* philos->life.philo_number);
	if (!philos->philo_var)
		ft_error(3);
	philos->writing = sem_open("write", O_CREAT | O_EXCL, 0666, 1);
	if (philos->writing == SEM_FAILED)
		ft_error(3);
	philos->eating = sem_open("eat", O_CREAT | O_EXCL, 0666, 1);
	if (philos->eating == SEM_FAILED)
		ft_error(3);
}

int	main(int arc, char **arv)
{
	t_philos	philos;

	if (arc < 5 || arc > 6)
	{
		ft_error(1);
		exit(1);
	}
	sem_unlink("write");
	sem_unlink("eat");
	sem_unlink("forks");
	if (arguments_parse(arc, arv, &philos.life))
		ft_error(1);
	main_init(&philos);
	philos_bonus(&philos);
	dismiss_philos(&philos);
}
