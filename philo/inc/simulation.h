/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/19 20:27:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include "philo.h"

typedef enum e_type
{
	LEFT,
	FIRST,
	RIGHT,
	FAILED,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_type;

/* --- routine threads --- */
void	*routine(void *arg);
void	take_fork(t_philo *philo, int hand);
int		lock_fork(pthread_mutex_t *fork);
int		unlock_fork(pthread_mutex_t *fork);
void	eat(t_philo *philo);
int		simulation_watcher(t_philo *philo);

/* --- print status ---*/
void	put_routine(t_philo *philo, int philo_id, int status);

#endif