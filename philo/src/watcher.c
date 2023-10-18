/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:02:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 20:36:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

bool	sim_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->conf->mute[STATUS]);
	if (philo->conf->done_eating == true || philo->conf->death == true)
	{
		pthread_mutex_unlock(&philo->conf->mute[STATUS]);
		return (true);
	}
	pthread_mutex_unlock(&philo->conf->mute[STATUS]);
	return (false);
}

bool	all_philo_ate(t_philo *philo)
{
	int	total;
	int	eat;
	int	i;

	i = -1;
	eat = 0;
	total = philo->conf->nbr_philo;
	while (++i < total)
	{
		pthread_mutex_lock(&philo[i].eat_lock);
		if (philo[i].eat_nb >= philo->conf->food_limit)
			eat++;
		pthread_mutex_unlock(&philo[i].eat_lock);
	}
	if (eat == total)
	{
		pthread_mutex_lock(&philo->conf->mute[STATUS]);
		philo->conf->done_eating = true;
		pthread_mutex_unlock(&philo->conf->mute[STATUS]);
		return (true);
	}
	return (false);
}

bool	check_death(time_t time, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[i].eat_lock);
	if (time - philo[i].last_ate >= philo->conf->time_death)
	{
		pthread_mutex_unlock(&philo[i].eat_lock);
		put_routine(philo, philo[i].id, DEAD);
		pthread_mutex_lock(&philo->conf->mute[STATUS]);
		philo->conf->death = true;
		pthread_mutex_unlock(&philo->conf->mute[STATUS]);
		return (true);
	}
	pthread_mutex_unlock(&philo[i].eat_lock);
	return (false);
}

bool	stop_factors(time_t time, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->conf->nbr_philo)
	{
		if (check_death(time_now(time, get_time()), philo, i) == true)
			return (true);
	}
	if (philo->conf->food_limit > 0)
		return (all_philo_ate(philo));
	return (false);
}

int	watcher(t_philo *philo)
{
	time_t	time;

	time = philo->conf->base_time;
	if (start_philosophers(philo) != SUCCEED)
		return (-1);
	if (lonely_philo(philo) == true)
		return (0);
	while ("watcher")
	{
		if (stop_factors(time, philo) == true)
			break ;
	}
	return (0);
}
