/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/21 17:08:10 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

/* --- ENUM --- */
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

/* --- THREADS --- */
void	*routine(void *arg);
void	take_fork(t_philo *philo, int hand);
int		lock_fork(pthread_mutex_t *fork);
int		unlock_fork(pthread_mutex_t *fork);
void	eat(t_philo *philo);
bool	sim_status(t_philo *philo);
int		simulation_watcher(t_philo *philo);

/* --- PRINT ---*/
void	put_routine(t_philo *philo, int philo_id, int status);

#endif