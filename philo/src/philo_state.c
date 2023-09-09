/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/09 13:48:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

void	thinks(t_philo *philo)
{
	time_t	time;

	time = timestamp(philo->conf->base_time, get_time());
	print_status(time, philo, philo->id, THINK);
	ft_usleep(philo->conf->time_sleep);
}

void	take_nap(t_philo *philo)
{
	time_t	time;

	time = timestamp(philo->conf->base_time, get_time());
	print_status(time, philo, philo->id, SLEEP);
	ft_usleep(philo->conf->time_sleep);
}

void	eat(t_philo *philo)
{
	time_t	time;

	if (philo->conf->food_limit > 0)
		philo->eat_nb++;
	time = timestamp(philo->conf->base_time, gettime());
	print_status(time, philo, philo->id, EAT);
	pthread_mutex_lock(&philo->conf->meal_lock);
	philo->last_ate = time;
	pthread_mutex_unlock(&philo->conf->meal_lock);
	ft_usleep(philo->conf->time_eat);
	pthread_mutex_unlock(&philo->conf->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->conf->fork[philo->id % philo->conf->nbr_philo]);
}

int	lock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != SUCCEED)
	{
		putendl_error(LOCK_ERR);
		return (FAILED);
	}
	return (SUCCEED);
}

void	take_fork(t_philo *philo, int hand)
{
	time_t	time;
	int		last;

	last = philo->conf->nbr_philo;
	if (hand == LEFT)
		lock_fork(&philo->conf->fork[philo->id - 1]);
	else if (hand == RIGHT)
		lock_fork(&philo->conf->fork[philo->id % philo->conf->nbr_philo]);
	time = timestamp(philo->conf->base_time, gettime());
	print_status(time, philo, philo->id, FORK);
}
