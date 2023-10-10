/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/10 13:56:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

void	eat(t_philo *philo)
{
	put_routine(philo, philo->id, EAT);
	pthread_mutex_lock(&philo->conf->mute[MUST_EAT]);
	philo->eat_nb++;
	pthread_mutex_unlock(&philo->conf->mute[MUST_EAT]);
	ft_usleep(philo->conf->time_eat);
	unlock_fork(&philo->conf->fork[philo->id - 1]);
	if (philo->id == FIRST)
		unlock_fork(&philo->conf->fork[philo->conf->nbr_philo - 1]);
	else
		unlock_fork(&philo->conf->fork[philo->id - 2]);
}

void	take_fork(t_philo *philo, int hand)
{
	if (hand == LEFT)
		lock_fork(&philo->conf->fork[philo->id - 1]);
	else if (hand == RIGHT)
	{
		if (philo->id == FIRST)
			lock_fork(&philo->conf->fork[philo->conf->nbr_philo - 1]);
		else
			lock_fork(&philo->conf->fork[philo->id - 2]);
	}
	put_routine(philo, philo->id, FORK);
}

static void	*lonely_routine(t_philo *philo)
{
	time_t	time;

	pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
	take_fork(philo, LEFT);
	ft_usleep(philo->conf->time_death);
	pthread_mutex_lock(&philo->conf->mute[TIME]);
	time = timestamp(philo->conf->base_time, get_time());
	pthread_mutex_unlock(&philo->conf->mute[TIME]);
	printf("%ld %d died\n", time, philo->id);
	unlock_fork(&philo->conf->fork[philo->id - 1]);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->conf->mute[NBR_PHILO]);
	if (philo->conf->nbr_philo == 1)
		return (lonely_routine(philo));
	pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
	if (philo->id % 2 == 0)
	{
		put_routine(philo, philo->id, THINK);
		ft_usleep(philo->conf->time_death / 3);
	}
	while (philo && !sim_status(philo))
	{
		take_fork(philo, LEFT);
		take_fork(philo, RIGHT);
		eat(philo);
		put_routine(philo, philo->id, SLEEP);
		ft_usleep(philo->conf->time_sleep);
		put_routine(philo, philo->id, THINK);
	}
	return (NULL);
}
