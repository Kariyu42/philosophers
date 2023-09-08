/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:28:12 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 08:47:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_timestamp(time_t origin, time_t current)
{
	time_t	res;

	res = current - origin;
	printf("%d ", res);
}

time_t	get_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) == -1)
		return (EXIT_FAILURE);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}
