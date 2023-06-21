#include "philo.h"



int	main (int arc, char **arv)
{
    t_arguments num;
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
