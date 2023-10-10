/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:13:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/10 10:05:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	putendl_error(char *error)
{
	int	i;

	i = -1;
	while (error[++i])
		ft_putchar_fd(error[i], STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

int	unlock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_unlock(fork) != 0)
	{
		putendl_error(UNLOCK_ERR);
		return (FAILED);
	}
	return (SUCCEED);
}

int	lock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != 0)
	{
		putendl_error(LOCK_ERR);
		return (FAILED);
	}
	return (SUCCEED);
}

bool	valid_argument(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (is_numeric(av[i]) == false)
		{
			putendl_error(USG_ERR);
			return (false);
		}
	}
	if (ft_atoi(av[1]) < 1)
	{
		putendl_error(NO_PHILO_ERR);
		return (false);
	}
	return (true);
}
