/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:17 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/22 23:08:26 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<pthread.h>
# include<sys/time.h>
# include<limits.h>
# include <stdio.h>

typedef struct arguments
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			max_meals;
	long			last_meal;
	int				id;
	int				time;
	int				time_start;
	int				*all_ate;
	int				*flg;
	pthread_mutex_t	*general;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*fork;
}	t_arguments;

typedef struct variables
{
	int				time_to_eat;
	int				id;
	int				time_to_sleep;
	int				max_meals;
	long			time_start;
	pthread_t		philo_threads;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*writing;
	long			last_meal;
	int				*flag;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*general;
	int				fin;
	t_arguments		*args;
}	t_variables;

void		ft_error(void);
int			ft_atoi(char	*n);
long		ft_timestamps(long time);
long long	get_time(void);
int			ft_usleep(int time);
void		tell_them(char *str, int id, long time, t_variables *var);
void		take_lfork(t_variables *philo);
int			take_rfork(t_variables *philo);
int			sleep_or_think(t_variables *philo);
int			eat(t_variables *philo);
void		*routine(void *arg);
int			max_meals_check(int arc, char **arv, t_arguments *num);
int			arguments_parsing(int arc, char **arv, t_arguments *num);
void		philo_dead(t_variables *var, int *finished, int inedx);
int			check_all_ate(int *tab, int size);
void		philo_check_helper(t_variables *var,
				int *finished, t_arguments *args);
int			philo_check(t_variables *philo, t_arguments *args, int index);
void		philos(t_arguments *num);

#endif