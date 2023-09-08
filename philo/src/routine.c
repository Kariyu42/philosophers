/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 15:02:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

void	eat(t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->conf->meal_lock);
	philo->last_ate = timestamp(philo->conf->base_time, get_time());
	pthread_mutex_unlock(&philo->conf->meal_lock);
	ft_usleep(philo->conf->time_eat);
	pthread_mutex_unlock(&philo->conf->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->conf->fork[philo->id % philo->conf->nbr_philo]);
	time = timestamp(philo->conf->base_time, gettime());
	print_status(time, philo, philo->id, EAT);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0) // if philo is pair wait time to eat...
		ft_usleep(philo->conf->time_eat);
	while (1)
	{
		//philo will take fork to left => lock the left fork => print message
		take_fork(philo, LEFT);
		// philo will take a fork to his right => lock fork on the right => print message
		take_fork(philo, RIGHT);
		// philo that took forks eat => print message => x time to eat... then DONE
		eat(philo);
	}
}
/*
* while (true)
* {
		philo sleeps
		philo thinks for x time => print message
* }
*/

/*
* philo x takes a fork to his left
* philo x takes a fork to his right and starts eating
* if philo couldn't take a fork then starts to think x time
* if philo is done 
*/
