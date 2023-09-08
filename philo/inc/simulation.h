/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:59:57 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 14:29:51 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	*routine(t_philo *philo);
void	take_fork(t_philo *philo, int hand);

/* --- print status ---*/
void	print_status(time_t time, t_philo *philo, int philo_id, int status);