/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:28:12 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/11 10:43:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	time_now(time_t origin, time_t current)
{
	return (current - origin);
}

time_t	get_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) == -1)
		return (EXIT_FAILURE);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}
