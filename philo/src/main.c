/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/17 09:51:57 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error.h"

static int	init_prog(int ac, char **av)
{
	t_settings	*conf;
	t_philo		*philo;

	conf = NULL;
	philo = NULL;
	if (valid_argument(ac, av) == false)
		return (EXIT_FAILURE);
	conf = handle_settings(ac, av);
	if (init_mutex(conf) != SUCCEED)
	{
		putendl_error(MUTEX_ERR);
		return (EXIT_FAILURE);
	}
	philo = init_philo(conf);
	if (!philo)
		return (EXIT_FAILURE);
	if (simulation_watcher(philo) == 0)
		return (SUCCEED);
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
// TODO create the forks (mutex) ✅
// TODO initialize philo ✅
// TODO create functions to start simulation ✅
// TODO lay out how the simulation will work ✅
// TODO set up watcher that will take care of philosopher status if dead ?
// TODO 
