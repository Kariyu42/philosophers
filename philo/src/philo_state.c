/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/19 20:30:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

void	eat(t_philo *philo)
{
	int	last;

	put_routine(philo, philo->id, EAT);
	pthread_mutex_lock(&philo->conf->meal_lock);
	last = 0;
	philo->last_ate = time;
	philo->eat_nb++;
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
	put_routine(philo, philo->id, FORK);
}
