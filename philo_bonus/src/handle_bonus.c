/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:47:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/25 08:07:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "simulation.h"
#include "error_bonus.h"

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

bool	argument_bonus(int ac, char **av)
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
