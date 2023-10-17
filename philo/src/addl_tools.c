/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:22:42 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/11 11:28:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_atoi(char *nbr)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (nbr[++i])
		res = res * 10 + (nbr[i] - '0');
	return (res);
}

bool	is_numeric(char *nbr)
{
	long	i;
	long	res;

	i = -1;
	res = 0;
	while (nbr[++i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (false);
		res = res * 10 + (nbr[i] - '0');
		if (res > INT_MAX)
			return (false);
	}
	return (true);
}
