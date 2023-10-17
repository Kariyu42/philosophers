/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/17 19:00:06 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

void	end_sim(t_settings *conf, t_philo *philo)
{
	int	i;

	(void)philo;
	i = -1;
	// while (++i < philo->conf->nbr_philo)
	// {
	// 	printf("oui: %d\n", i);
	// 	pthread_join(philo[i].thread, NULL);
	// }
	i = -1;
	while (++i < conf->nbr_philo)
	{
		printf("non: %d\n", i);
		pthread_mutex_destroy(&(conf->fork[i]));
	}
}

void	put_routine(t_philo *philo, int philo_id, int status)
{
	time_t	time;

	pthread_mutex_lock(&philo->conf->mute[PRINT]);
	time = time_now(philo->conf->base_time, get_time());
	if (philo->conf->death == true)
	{
		pthread_mutex_unlock(&philo->conf->mute[PRINT]);
		return ;
	}
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo_id);
	else if (status == EAT)
	{
		philo->last_ate = time;
		printf("%ld %d is eating\n", time, philo_id);
	}
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo_id);
	else if (status == DEAD)
	{
		pthread_mutex_lock(&philo->conf->mute[STATUS]);
		philo->conf->death = true;
		pthread_mutex_unlock(&philo->conf->mute[STATUS]);
		printf("%ld %d is dead\n", time, philo_id);
	}
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
