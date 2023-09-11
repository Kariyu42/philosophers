/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/11 13:49:23 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

// watcher
// static void	check_status(t_philo **philo)
// {
// 	int	i;

// 	i = 0;
// 	while (1)
// 	{
// 		if (check_philo_status(philo[i]) == DEAD)
// 		{
// 			// * print that philo dies
// 			// * free all table structure.
// 			// TODO figure how to structure the watcher.
// 		}
// 		// i++;
// 		// if (i == philo[i]->conf->nbr_philo)
// 		// i = 0;
// 	}
// }
// ! place a watcher that will be in charge of analyzing the status of philo
// ! if one dies or are they done eating (if we add an additional argument)?
// TODO

void	*routine(void *caca)
{
	t_philo	*philo = (t_philo *)caca;
	if (philo->id % 2 == 0)
		ft_usleep(philo->conf->time_eat);
	while (1)
	{
		take_fork(philo, LEFT);
		take_fork(philo, RIGHT);
		eat(philo);
		take_nap(philo);
		thinks(philo);
	}
	return (NULL);
}
