/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/19 20:18:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error.h"

static int	init_prog(int ac, char **av)
{
	t_settings	*conf;
	t_philo		*philo;

	if (valid_argument(ac, av) == false)
		return (FAILED);
	conf = handle_settings(ac, av);
	if (init_mutex(conf) != SUCCEED)
	{
		putendl_error(MUTEX_ERR);
		return (FAILED);
	}
	philo = init_philo(conf);
	if (!philo)
	{
		putendl_error(THREAD_ERR);
		return (FAILED);
	}
	simulation_watcher(philo);
	return (SUCCEED);
}

int	main(int ac, char **av)
{
	if (ac == COR_ARG || ac == ADDL_ARG)
	{
		if (init_prog(ac, av) != SUCCEED)
			return (EXIT_FAILURE);
	}
	else
	{
		putendl_error(ARG_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
* ./philo [no. of philosopher] [time to die] [time to eat]
* [time to sleep] [no. of times each philosopher must eat]
*/
// TODO set up watcher that will take care of philosopher status if dead ?
