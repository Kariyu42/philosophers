/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/16 06:44:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

static bool	death_sentence(time_t time, time_t last_ate)
{
	if (time - last_ate <= TIMEOUT)
		return (true);
	return (false);
}

// watcher
int	simulation_watcher(t_philo *philo)
{
	int		i;
	time_t	time;

	i = 1;
	ft_usleep(philo->conf->time_eat);
	while (1)
	{
		time = timestamp(philo->conf->base_time, get_time());
		if (death_sentence(time, philo[i].last_ate) == true)
		{
			time = timestamp(philo[i].conf->base_time, get_time());
			print_status(time, philo, philo[i].id, DEAD);
			break ;
		}
		i++;
		if (i == philo->conf->nbr_philo)
			i = 1;
	}
	return (0);
}
// ! place a watcher that will be in charge of analyzing the status of philo
// ! if one dies or they are done eating (6th arg)
// TODO change argument of while loop to check status of all philos. Using a watcher.
// TODO without making them communicate with each other.

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->conf->time_eat);
	while (1)
	{
		take_fork(philo, LEFT);
		take_fork(philo, RIGHT);
		eat(philo);
		take_nap(philo);
		thinks(philo);
	}
	return (NULL);
}
