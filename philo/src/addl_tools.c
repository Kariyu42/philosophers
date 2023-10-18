/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:22:42 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 20:36:33 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"
#include <limits.h>

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_atoi(char *nbr)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (nbr[++i])
		res = res * 10 + (nbr[i] - '0');
	return (res);
}

bool	lonely_philo(t_philo *philo)
{
	if (philo->conf->nbr_philo == 1)
	{
		ft_usleep(philo->conf->time_death * 2);
		return (true);
	}
	return (false);
}

int	start_philosophers(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->conf->nbr_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (putendl_error(THREAD_ERR));
	}
	return (SUCCEED);
}

bool	is_numeric(char *nbr)
{
	long	i;
	long	res;

	i = -1;
	res = 0;
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
