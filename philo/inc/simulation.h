/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/12 13:02:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include "philo.h"

typedef enum e_type
{
	TIMEOUT,
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
void	*routine(void *caca);
void	take_fork(t_philo *philo, int hand);
void	eat(t_philo *philo);
void	take_nap(t_philo *philo);
void	thinks(t_philo *philo);
int		simulation_watcher(t_philo **philo);

/* --- print status ---*/
void	print_status(time_t time, t_philo *philo, int philo_id, int status);

#endif