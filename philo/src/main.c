/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 10:43:32 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

// watcher
static void	begin_simulation(t_philo **philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if ()
		i++;
		if (i == philo[i]->conf->nbr_philo)
			i = 0;
	}
}

static int	init_prog(int ac, char **av)
{
	t_settings	*conf;
	t_philo		*philo;

	conf = NULL;
	philo = NULL;
	if (valid_argument(ac, av) == false)
		return (EXIT_FAILURE);
	if (handle_arg(ac, av, &conf, &philo) == false)
		return (EXIT_FAILURE);
	begin_simulation(&philo);
	// * begin the simulation. {}
		// ? How should I free if simulation ends or fails.
	return (SUCCEED);
}

int	main(int ac, char **av)
{
	if (ac == COR_ARG || ac == ADDL_ARG)
		if (init_prog(ac, av) != SUCCEED)
			return (EXIT_FAILURE);
	else
	{
		putendl_error(ARG_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// * ./philo [no. of philosopher] [time to die] [time to eat]
// *[time to sleep] [no. of times each philosopher must eat]
//TODO create the forks (mutex) ✅
// TODO initialize philo ✅
// TODO lay out how tthe simulation will work
// TODO create functions to start simulation