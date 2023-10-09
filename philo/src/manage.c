/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/09 11:45:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

void	end_sim(t_settings *conf, t_philo *philo)
{
	long	i;

	(void)conf;
	i = -1;
	while (++i < philo->conf->nbr_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < conf->nbr_philo)
		pthread_mutex_destroy(&(conf->fork[i]));
}

void	put_routine(t_philo *philo, int philo_id, int status)
{
	time_t	time;

	pthread_mutex_lock(&philo->conf->mute[PRINT]);
	if (philo->conf->death == true)
		return ;
	pthread_mutex_lock(&philo->conf->mute[TIME]);
	time = timestamp(philo->conf->base_time, get_time());
	pthread_mutex_unlock(&philo->conf->mute[TIME]);
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo_id);
	else if (status == EAT)
	{
		pthread_mutex_lock(&philo->conf->mute[LAST_ATE]);
		philo->last_ate = time;
		pthread_mutex_unlock(&philo->conf->mute[LAST_ATE]);
		printf("%ld %d is eating\n", time, philo_id);
	}
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo_id);
	pthread_mutex_unlock(&philo->conf->mute[PRINT]);
}

int	check_philo(t_philo *philo, t_settings *conf)
{
	int	i;

	i = -1;
	if (!philo)
	{
		while (++i < conf->nbr_philo)
			pthread_mutex_destroy(&(conf->fork[i]));
		return (putendl_error(THREAD_ERR));
	}
	return (SUCCEED);
}

int	manage_mutex(t_settings *conf)
{
	int	err_type;

	err_type = init_mutex(conf);
	if (err_type == ALLOC)
		return (putendl_error(ALLOC_ERR));
	else if (err_type == FAILED)
		return (putendl_error(MUTEX_ERR));
	return (SUCCEED);
}
