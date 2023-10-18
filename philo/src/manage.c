/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 18:03:28 by kquetat-         ###   ########.fr       */
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
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (putendl_error(JOIN_ERR));
		if (pthread_mutex_destroy(&philo[i].eat_lock) != 0)
			return (putendl_error(DESTROY_ERR));
		if (pthread_mutex_destroy(&conf->fork[i]) != 0)
			return (putendl_error(DESTROY_ERR));
		if (i < NBR_MUTEXES)
		{
			if (pthread_mutex_destroy(&conf->mute[i]) != 0)
				return (putendl_error(DESTROY_ERR));
		}
	}
	// free(philo);
	// free(conf);
	return (SUCCEED);
}

// ! Must set variable the state of simulation to true in order to exit.
void	put_routine(t_philo *ph, int id, int status)
{
	time_t	time;

	pthread_mutex_lock(&ph->conf->mute[PRINT]);
	if (ph->conf->death == true)
	{
		pthread_mutex_unlock(&ph->conf->mute[PRINT]);
		return ;
	}
	time = time_now(ph->conf->base_time, get_time());
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, id);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, id);
	else if (status == DEAD)
		printf("%ld %d is dead\n", time, id);
	pthread_mutex_unlock(&ph->conf->mute[PRINT]);
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
