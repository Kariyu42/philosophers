/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/08/30 14:25:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	ft_atoi(char *nbr)
{
	int	i;
	int	res;

	i = -1;
	while (nbr[++i])
		res = res * 10 + (nbr[i] - '0');
	return (res);
}

bool	is_numeric(char *nbr)
{
	long	i;
	long	res;

	i = -1;
	while (nbr[++i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (false);
		res = res * 10 + (nbr[i] - '0');
		if (res > INT_MAX)
			return (false);
	}
	return (true);
}

void	set_up(t_settings *config, int ac, char **av)
{
	config->nbr_philo = ft_atoi(av[1]);
	config->time_death = ft_atoi(av[2]);
	config->time_eat = ft_atoi(av[3]);
	config->time_sleep = ft_atoi(av[4]);
	if (ac == ADDL_ARG)
		config->food_limit = ft_atoi(av[5]);
	config->base_time = get_time();
}
