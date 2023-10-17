/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/17 19:14:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

int	eat(t_philo *philo)
{
	if (lock_fork(philo, &philo->conf->fork[philo->id - 1]) != 0)
		return (FAILED);
	if (lock_fork(philo, &philo->conf->fork[philo->id % philo->conf->nbr_philo]))
		return (FAILED);
	put_routine(philo, philo->id, EAT);
	pthread_mutex_lock(&philo->eat_lock);
	philo->eat_nb++;
	pthread_mutex_unlock(&philo->eat_lock);
	ft_usleep(philo->conf->time_eat);
	unlock_fork(&philo->conf->fork[philo->id - 1]);
	if (philo->id == FIRST)
		unlock_fork(&philo->conf->fork[philo->conf->nbr_philo - 1]);
	else
		unlock_fork(&philo->conf->fork[philo->id - 2]);
	return (SUCCEED);
}

void	take_fork(t_philo *philo, int hand)
{
	else if (hand == RIGHT)
	{
		if (philo->id == FIRST)
			lock_fork(&philo->conf->fork[philo->conf->nbr_philo - 1]);
		else
			lock_fork(&philo->conf->fork[philo->id - 2]);
	}
}

static bool	one_philo_sim(t_philo *philo)
{
	time_t	time;

	if (philo->conf->nbr_philo == 1)
	{
		take_fork(philo, LEFT);
		ft_usleep(philo->conf->time_death);
		time = time_now(philo->conf->base_time, get_time());
		printf("%ld %d died\n", time, philo->id);
		unlock_fork(&philo->conf->fork[philo->id - 1]);
		return (true);
	}
	return (false);
}

void	philo_wait(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		put_routine(philo, philo->id, THINK);
		ft_usleep(philo->conf->time_death / 3);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (one_philo_sim(philo))
		return (NULL);
	philo_wait(philo);
	while (!sim_status(philo))
	{
		if (eat(philo) != SUCCEED)
			break ;
		put_routine(philo, philo->id, SLEEP);
		ft_usleep(philo->conf->time_sleep);
		put_routine(philo, philo->id, THINK);
	}
	return (NULL);
}
