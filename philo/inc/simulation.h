/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/17 09:20:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include "philo.h"

typedef enum e_type
{
	TIMEOUT,
	FIRST,
	LEFT,
	RIGHT,
	FAILED,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_type;

/* --- routine threads --- */
void	*routine(void *caca);
void	take_fork(t_philo *philo, int hand);
int		lock_fork(pthread_mutex_t *fork);
int		unlock_fork(pthread_mutex_t *fork);
void	eat(t_philo *philo);
void	take_nap(t_philo *philo);
void	thinks(t_philo *philo);
int		simulation_watcher(t_philo *philo);

/* --- print status ---*/
void	print_status(time_t time, t_philo *philo, int philo_id, int status);

#endif