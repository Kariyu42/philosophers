/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 19:30:36 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

int	eat(t_philo *ph)
{
	if (lock_fork(ph, &ph->conf->fork[ph->id - 1]) != 0)
		return (FAILED);
	if (lock_fork(ph, &ph->conf->fork[ph->id % ph->conf->nbr_philo]) != 0)
		return (FAILED);
	put_routine(ph, ph->id, EAT);
	pthread_mutex_lock(&ph->eat_lock);
	ph->eat_nb++;
	pthread_mutex_unlock(&ph->eat_lock);
	ft_usleep(ph->conf->time_eat);
	if (unlock_fork(&ph->conf->fork[ph->id - 1]) != 0)
		return (FAILED);
	if (unlock_fork(&ph->conf->fork[ph->id % ph->conf->nbr_philo]) != 0)
		return (FAILED);
	return (SUCCEED);
}

static void	philo_wait(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		put_routine(philo, philo->id, THINK);
		ft_usleep(50);
	}
}

static int	one_philo_sim(t_philo *ph)
{
	time_t	time;

	if (ph->conf->nbr_philo == 1)
	{
		if (lock_fork(ph, &ph->conf->fork[ph->id - 1]) != 0)
			return (FAILED);
		ft_usleep(ph->conf->time_death);
		time = time_now(ph->conf->base_time, get_time());
		printf("%ld %d died\n", time, ph->id);
		if (unlock_fork(&ph->conf->fork[ph->id - 1]) != 0)
			return (FAILED);
		return (1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (one_philo_sim(philo) > 0)
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
