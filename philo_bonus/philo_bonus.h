/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:51:07 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/25 00:20:58 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<pthread.h>
# include<semaphore.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<signal.h>
# include<limits.h>
# include<sys/time.h>

typedef struct argumments
{
	int	philo_number;
	int	max_meals;
	int	die;
	int	eat;
	int	sleep;
}	t_argumments;

typedef struct variables
{
	int				id;
	int				n_eat;
	pid_t			pid;
	long long		last_meal;
	long long		next_eat;
	struct philos	*cmn_data;
}	t_variables;

typedef struct philos
{
	t_variables		*philo_var;
	sem_t			*forks;
	sem_t			*writing;
	sem_t			*eating;
	t_argumments	life;
}	t_philos;

void		ft_error(int i);
int			ft_atoi(char	*n);
long long	ft_timestamps(void);
int			arguments_parse(int arc, char **arv, t_argumments *life);
void		tell_them(t_variables *philo, char *str);
void		ft_usleep(long long msec);
void		philo_eat(t_variables *philo);
void		philo_sleep(t_variables *philo);
void		*routine(void *arg);
void		philosopher(t_variables *var);
void		philos_bonus(t_philos *philos);
void		kill_all_philos(t_philos *philo);
void		dismiss_philos(t_philos *philo);

#endif
