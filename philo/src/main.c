/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/12 14:20:54 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error.h"

t_settings	*handle_settings(int ac, char **av)
{
	t_settings	*config;

	config = ft_calloc(1, sizeof(t_settings));
	config->nbr_philo = ft_atoi(av[1]);
	config->time_death = ft_atoi(av[2]);
	config->time_eat = ft_atoi(av[3]);
	config->time_sleep = ft_atoi(av[4]);
	if (ac == ADDL_ARG)
		config->food_limit = ft_atoi(av[5]);
	else
		config->food_limit = 0;
	config->base_time = get_time();
}

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
		return (false);
	}
	philo = init_philo(conf);
	if (!philo)
		return (EXIT_FAILURE);
	if (simulation_watcher(&philo) == 0)
		return (SUCCEED);
	return (SUCCEED);
}

int	main(int ac, char **av)
{
	// setbuf(stdout, NULL);
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
