/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:07:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 14:56:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

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
