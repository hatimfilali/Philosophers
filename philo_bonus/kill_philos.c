/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:49:56 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 18:51:02 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philos(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->life.philo_number)
		kill(philo->philo_var[i++].pid, SIGTERM);
}

void	close_semaphores(t_philos *philo)
{
	if (sem_close(philo->forks) || sem_close(philo->eating)
		|| sem_close(philo->writing))
		ft_error(3);
	if (sem_unlink("forks"))
		ft_error(3);
	if (sem_unlink("eat"))
		ft_error(3);
	if (sem_unlink("write"))
		ft_error(3);
}

void	dismiss_philos(t_philos *philo)
{
	int	i;
	int	status;

	i = 0;
	while (i < philo->life.philo_number)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 1)
			{
				kill_all_philos(philo);
				break ;
			}
		}
		else if (WIFSIGNALED(status))
		{
			printf("A PHILO HAS BEEN EXECUTED\n");
			kill_all_philos(philo);
			break ;
		}
		i++;
	}
	close_semaphores(philo);
}
