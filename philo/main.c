/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:42:06 by hfilali           #+#    #+#             */
/*   Updated: 2023/06/22 23:26:59 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_arguments	num;

	if (arc < 5 || arc > 6)
	{
		ft_error();
		return (1);
	}
	if (arguments_parsing(arc, arv, &num) == 0)
		philos(&num);
	else
		return (1);
}
