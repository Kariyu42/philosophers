/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/07 14:53:25 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

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
		return (false);
	return (true);
}

static bool	handle_arg(int ac, char **av, t_settings **conf, t_philo **philo)
{
	*conf = ft_calloc(1, sizeof(t_settings));
	set_up_configs(*conf, ac, av);
	if (init_mutex(*conf) != SUCCEED)
	{
		putendl_error(INIT_ERR);
		return (false);
	}
	if (init_philo(*philo, *conf) != SUCCEED)
		return (false);
	return (true);
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

	// * begin the simulation. {}
		// ? How should I free if simulation ends or fails.
	return (SUCCEED);
}

int	main(int ac, char **av)
{
	if (ac == COR_ARG || ac == ADDL_ARG)
		if (init_prog(ac, av) != SUCCEED)
			return (EXIT_SUCCESS);
	else
	{
		write(STDERR_FILENO, ARG_ERR, 33);
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