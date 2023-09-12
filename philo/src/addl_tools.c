/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addl_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:22:42 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/12 13:12:59 by kquetat-         ###   ########.fr       */
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

static void	ft_bzero(void *str, size_t n)
{
	unsigned int	i;
	i = -1;
	while (++i < n)
		((char *) str)[i] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && (((size_t) - 1) / size) < count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
