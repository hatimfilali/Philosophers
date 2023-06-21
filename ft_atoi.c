#include "philo.h"


int	fill_int(long nbr, int i, char *n, int neg)
{
	while (n[i] <= '9' && n[i] >= '0')
	{
		nbr = nbr * 10 + (n[i] - 48);
		if (((nbr * neg) > 2147483647) || ((nbr * neg) < -2147483648))
			ft_error();
		i++;
	}
	if (n[i] != ' ' && n[i] != '\t' && n[i] != '\r'
		&& n[i] != '\n' && n[i] != '\v' && n[i] != '\f' && n[i])
	{
		ft_error();
		exit(1);
	}
	if (neg == -1)
		return (-nbr);
	return (nbr);
}

int	ft_atoi(char	*n)
{
	int					i;
	int					neg;
	unsigned long long	nbr;

	nbr = 0;
	i = 0;
	neg = 1;
	while (n[i] == ' ' || n[i] == '\t' || n[i] == '\r'
		|| n[i] == '\n' || n[i] == '\v' || n[i] == '\f')
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			neg = -1;
		i++;
	}
	return (fill_int(nbr, i, n, neg));
}
