/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 14:31:19 by kquetat-         ###   ########.fr       */
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
int		lock_fork(t_philo *philo, pthread_mutex_t *fork);
int		unlock_fork(pthread_mutex_t *fork);
int		eat(t_philo *philo);
bool	sim_status(t_philo *philo);
int		watcher(t_philo *philo);

/* --- PRINT ---*/
void	put_routine(t_philo *philo, int philo_id, int status);

#endif