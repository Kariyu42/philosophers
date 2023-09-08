/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 12:10:32 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"

int	lock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != SUCCEED)
		return (FAILED);
	return (SUCCEED);
}

void	take_fork(t_philo *philo, int hand)
{
	int	last;

	last = philo->conf->nbr_philo;
	if (hand == LEFT)
	{
		lock_fork(&philo->conf->mutex[philo->id]);
		// pthread_mutex_unlock(&philo->conf->mutex[philo->id]);
	}
	else if (hand == RIGHT)
	{
		if (philo->id == FIRST)
			lock_fork(&philo->conf->mutex[last]);
		else if (philo->id == last)
			lock_fork(&philo->conf->mutex[FIRST]);
		else
			lock_fork(&philo->conf->mutex[philo->id - 1]);
		//pthread_mutex_unlock();
	}
	print_status(philo->id, FORK);
}