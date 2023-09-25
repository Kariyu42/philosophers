/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:59:47 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/25 08:00:16 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	timestamp(time_t origin, time_t current)
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