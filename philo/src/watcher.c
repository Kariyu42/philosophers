/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:02:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/29 16:53:02 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

bool	sim_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->conf->mute[STATUS]);
	if (philo->conf->done_eating == true)
	{
		pthread_mutex_unlock(&philo->conf->mute[STATUS]);
		return (true);
	}
	pthread_mutex_unlock(&philo->conf->mute[STATUS]);
	return (false);
}

static bool	all_philo_ate(t_philo *philo)
{
	long	total;
	long	eat;
	long	i;

	i = -1;
	eat = 0;
	pthread_mutex_lock(&philo->conf->mute[NBR_PHILO]);
	total = philo->conf->nbr_philo;
	pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
	while (++i < total)
	{
		pthread_mutex_lock(&philo->conf->mute[MUST_EAT]);
		if (philo->conf->food_limit > 0 && \
			philo[i].eat_nb >= philo->conf->food_limit)
			eat++;
		pthread_mutex_unlock(&philo->conf->mute[MUST_EAT]);
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

static bool	check_death(time_t time, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->conf->mute[LAST_ATE]);
	if (time - philo[i].last_ate >= philo->conf->time_death)
	{
		pthread_mutex_lock(&philo->conf->mute[PRINT]);
		printf("%ld %d died\n", time, philo[i].id);
		philo->conf->death = true;
		pthread_mutex_unlock(&philo->conf->mute[PRINT]);
		return (true);
	}
	pthread_mutex_unlock(&philo->conf->mute[LAST_ATE]);
	return (false);
}

static bool	lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->conf->mute[NBR_PHILO]);
	if (philo->conf->nbr_philo == 1)
	{
		pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
		ft_usleep(philo->conf->time_death * 2);
		return (true);
	}
	pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
	return (false);
}

int	watcher(t_philo *philo)
{
	long	exceed;
	time_t	time;
	long	i;

	i = 0;
	pthread_mutex_lock(&philo->conf->mute[TIME]);
	time = philo->conf->base_time;
	pthread_mutex_unlock(&philo->conf->mute[TIME]);
	pthread_mutex_lock(&philo->conf->mute[NBR_PHILO]);
	exceed = philo->conf->nbr_philo;
	pthread_mutex_unlock(&philo->conf->mute[NBR_PHILO]);
	if (lonely_philo(philo) == true)
		return (0);
	while ("watcher")
	{
		if (check_death(timestamp(time, get_time()), philo, i) == true)
			break ;
		if (philo->conf->food_limit > 0 && all_philo_ate(philo) == true)
			break ;
		i++;
		if (i == exceed)
			i = 0;
		ft_usleep(1000);
	}
	return (0);
}
