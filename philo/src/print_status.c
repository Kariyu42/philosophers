/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:48:17 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/19 20:27:03 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"

void	put_routine(t_philo *philo, int philo_id, int status)
{
	time_t	time;

	pthread_mutex_lock(&philo->conf->put_status);
	time = timestamp(philo->conf->base_time, get_time());
	if (status == FORK)
		printf("%ld %d has taken a fork\n", time, philo_id);
	else if (status == EAT)
		printf("%ld %d is eating\n", time, philo_id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", time, philo_id);
	pthread_mutex_unlock(&philo->conf->put_status);
}
