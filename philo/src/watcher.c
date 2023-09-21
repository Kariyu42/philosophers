/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:02:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/21 19:56:21 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

bool	sim_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->conf->limit_lock);
	if (philo->conf->done_eating == true)
		return (true);
	pthread_mutex_unlock(&philo->conf->limit_lock);
	return (false);
}

static bool	all_philo_ate(t_philo *philo)
{
	long	total;
	long	eat;
	long	i;

	i = -1;
	eat = 0;
	total = philo->conf->nbr_philo;
	while (++i < philo->conf->nbr_philo)
	{
		if (philo->conf->food_limit > 0 && \
			philo[i].eat_nb >= philo->conf->food_limit)
			eat++;
		if (eat == total)
		{
			pthread_mutex_lock(&philo->conf->limit_lock);
			philo->conf->done_eating = true;
			pthread_mutex_unlock(&philo->conf->limit_lock);
			return (true);
		}
	}
	return (false);
}

static bool	check_death(time_t time, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->conf->food_nbr);
	if (time - philo[i].last_ate >= philo->conf->time_death)
	{
		pthread_mutex_lock(&philo->conf->put_status);
		printf("%ld %d died\n", time, philo[i].id);
		return (true);
	}
	pthread_mutex_unlock(&philo->conf->food_nbr);
	return (false);
}

int	simulation_watcher(t_philo *philo)
{
	long	exceed;
	time_t	time;
	long	i;

	if (philo->conf->nbr_philo == 1)
	{
		ft_usleep(philo->conf->time_death);
		return (0);
	}
	i = 0;
	exceed = philo->conf->nbr_philo;
	while ("watcher")
	{
		time = timestamp(philo->conf->base_time, get_time());
		if (check_death(time, philo, i) == true)
			break ;
		if (all_philo_ate(philo) == true)
			break ;
		i++;
		if (i == exceed)
			i = 0;
	}
	return (0);
}
