/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:08:31 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/17 09:11:14 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error.h"

int	unlock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_unlock(fork) != SUCCEED)
	{
		putendl_error(UNLOCK_ERR);
		return (FAILED);
	}
	return (SUCCEED);
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
