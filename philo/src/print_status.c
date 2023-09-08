/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:48:17 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 12:10:00 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
/*
? Should the messages be protected by mutexes.
TODO must try on the go...
*/
void	print_status(int philo_id, int status)
{
	if (status == FORK)
		printf("%d has taken a fork\n", philo_id);
	else if (status == EAT)
		printf("%d is eating\n", philo_id);
	else if (status == SLEEP)
		printf("%d is sleeping\n", philo_id);
	else if (status == THINK)
		printf("%d is thinking\n", philo_id);
}
