/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 20:32:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

int	end_sim(t_settings *conf, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->conf->nbr_philo)
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (putendl_error(JOIN_ERR));
	i = -1;
	while (++i < philo->conf->nbr_philo)
	{
		if (pthread_mutex_destroy(&conf->fork[i]) != 0)
			return (putendl_error(DESTROY_ERR));
		if (pthread_mutex_destroy(&philo[i].eat_lock) != 0)
			return (putendl_error(DESTROY_ERR));
		if (i < NBR_MUTEXES)
		{
			if (pthread_mutex_destroy(&conf->mute[i]) != 0)
				return (putendl_error(DESTROY_ERR));
		}
	}
	free(philo);
	free(conf->fork);
	free(conf);
	return (SUCCEED);
}

void	eat_action(t_philo *ph, int id, time_t time)
{
	pthread_mutex_lock(&ph->eat_lock);
	ph->last_ate = time;
	pthread_mutex_unlock(&ph->eat_lock);
	printf("%ld %d is eating\n", time, id);
}

bool	death_status(t_philo *ph)
{
	pthread_mutex_lock(&ph->conf->mute[STATUS]);
	if (ph->conf->death == true)
	{
		pthread_mutex_unlock(&ph->conf->mute[PRINT]);
		pthread_mutex_unlock(&ph->conf->mute[STATUS]);
		return (true);
	}
	pthread_mutex_unlock(&ph->conf->mute[STATUS]);
	return (false);
}

void	put_routine(t_philo *ph, int id, int status)
{
	time_t	time;

	pthread_mutex_lock(&ph->conf->mute[PRINT]);
	if (death_status(ph) == true)
		return ;
	time = time_now(ph->conf->base_time, get_time());
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, id);
	else if (status == EAT)
		eat_action(ph, id, time);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, id);
	else if (status == DEAD)
		printf("%ld %d is dead\n", time, id);
	pthread_mutex_unlock(&ph->conf->mute[PRINT]);
}
