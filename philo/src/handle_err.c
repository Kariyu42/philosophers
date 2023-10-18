/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:13:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 14:35:20 by kquetat-         ###   ########.fr       */
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
	return (-1);
}

int	unlock_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_unlock(fork) != SUCCEED)
	{
		putendl_error(UNLOCK_ERR);
		return (FAILED);
	}
	return (SUCCEED);
}

int	lock_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) != SUCCEED)
	{
		putendl_error(LOCK_ERR);
		return (FAILED);
	}
	put_routine(philo, philo->id, FORK);
	return (SUCCEED);
}

int	valid_argument(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (is_numeric(av[i]) == false)
			return (-1);
	if (ft_atoi(av[1]) < 1)
		return (-1);
	return (1);
}
