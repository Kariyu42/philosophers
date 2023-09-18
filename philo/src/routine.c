/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/18 19:21:02 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

static bool	death_sentence(time_t time, time_t last_ate, time_t death_time)
{
	if (time - last_ate >= death_time)
		return (true);
	return (false);
}

// watcher
int	simulation_watcher(t_philo *philo)
{
	long	i;
	long	exceed;
	time_t	time;

	i = 0;
	exceed = philo->conf->nbr_philo;
	// ! printf must be removed
	// printf("exceed: %ld\n", exceed);
	ft_usleep(philo->conf->time_eat);
	while ("watcher")
	{
		time = timestamp(philo->conf->base_time, get_time());
		// ! printf must be removed
		// printf("philo last ate = %ld\n", philo[5].last_ate);
		if (death_sentence(time, philo[i].last_ate, \
			philo->conf->time_death) == true)
		{
			time = timestamp(philo->conf->base_time, get_time());
			print_status(time, philo, philo[i].id, DEAD);
			break ;
		}
		i++;
		if (i == exceed)
			i = 0;
	}
	return (0);
}
// ! place a watcher that will be in charge of analyzing the status of philo
// TODO change argument of while loop to check status of all philos. Using a watcher.
// TODO Analyze each philo if they are done eating x times all of them.

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
