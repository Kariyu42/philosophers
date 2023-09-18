/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/18 19:29:50 by kquetat-         ###   ########.fr       */
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
	int		last;

	last = 0;
	philo->eat_nb++;
	time = timestamp(philo->conf->base_time, get_time());
	print_status(time, philo, philo->id, EAT);
	pthread_mutex_lock(&philo->conf->meal_lock);
	philo->last_ate = time;
	// printf("\033[38;5;224mlast_ate: %ld\033[0m\n", philo->last_ate);
	pthread_mutex_unlock(&philo->conf->meal_lock);
	ft_usleep(philo->conf->time_eat);
	unlock_fork(&philo->conf->fork[philo->id - 1]);
	if (philo->id == FIRST)
	{
		last = philo->conf->nbr_philo;
		unlock_fork(&philo->conf->fork[last - 1]);
	}
	else
		unlock_fork(&philo->conf->fork[philo->id - 2]);
}

void	take_fork(t_philo *philo, int hand)
{
	time_t	time;
	int		last;

	last = philo->conf->nbr_philo;
	if (hand == LEFT)
		lock_fork(&philo->conf->fork[philo->id - 1]);
	else if (hand == RIGHT)
	{
		if (philo->id == FIRST)
			lock_fork(&philo->conf->fork[last - 1]);
		else
			lock_fork(&philo->conf->fork[philo->id - 2]);
	}
	time = timestamp(philo->conf->base_time, get_time());
	print_status(time, philo, philo->id, FORK);
}
