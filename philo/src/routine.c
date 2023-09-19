/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/19 20:28:06 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

static bool	death_sentence(time_t time, time_t last_ate, t_philo *philo)
{
	if (time - last_ate >= philo->conf->time_death)
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
	ft_usleep(philo->conf->time_eat);
	while ("watcher")
	{
		time = timestamp(philo->conf->base_time, get_time());
		if (death_sentence(time, philo[i].last_ate, philo) == true)
		{
			put_routine(philo, philo[i].id, DEAD);
			break ;
		}
		i++;
		if (i == exceed)
			i = 0;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		put_routine(philo, philo->id, THINK);
		ft_usleep(philo->conf->time_death / 3);
	}
	while (1)
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
