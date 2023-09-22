/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/22 18:33:21 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

void	end_sim(t_settings *conf, t_philo *philo)
{
	long	i;

	i = -1;
	while (++i < philo->conf->nbr_philo)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < conf->nbr_philo)
		pthread_mutex_destroy(&(conf->fork[i]));
	pthread_mutex_destroy(&conf->put_status);
	pthread_mutex_destroy(&conf->meal_lock);
	pthread_mutex_destroy(&conf->food_nbr);
	pthread_mutex_destroy(&conf->limit_lock);
}

void	put_routine(t_philo *philo, int philo_id, int status)
{
	time_t	time;

	pthread_mutex_lock(&philo->conf->put_status);
	time = timestamp(philo->conf->base_time, get_time());
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo_id);
	else if (status == EAT)
	{
		pthread_mutex_lock(&philo->conf->food_nbr);
		philo->last_ate = time;
		pthread_mutex_unlock(&philo->conf->food_nbr);
		printf("%ld %d is eating\n", time, philo_id);
	}
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo_id);
	pthread_mutex_unlock(&philo->conf->put_status);
}

int	check_philo(t_philo *philo, t_settings *conf)
{
	int	i;

	i = -1;
	if (!philo)
	{
		while (++i < conf->nbr_philo)
			pthread_mutex_destroy(&(conf->fork[i]));
		pthread_mutex_destroy(&conf->put_status);
		pthread_mutex_destroy(&conf->meal_lock);
		pthread_mutex_destroy(&conf->food_nbr);
		pthread_mutex_destroy(&conf->limit_lock);
		free(conf->fork);
		free(conf);
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
	{
		free(conf);
		return (putendl_error(MUTEX_ERR));
	}
	return (SUCCEED);
}
