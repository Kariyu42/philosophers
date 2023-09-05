/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/05 21:27:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_settings	*handle_arg(int ac, char **av)
{
	int			i;
	t_settings	*config;

	i = 0;
	config = NULL;
	while (++i < ac)
	{
		if (is_numeric(av[i]) == false)
		{
			write(STDERR_FILENO, USG_ERR, 35);
			return (false);
		}
	}
	config = malloc(sizeof(t_settings));
	if (!config)
		return (NULL);
	set_up(config, ac, av);
	return (config);
}

int	main(int ac, char **av)
{
	t_settings	*config;

	config = NULL;
	if (ac == COR_ARG || ac == ADDL_ARG)
	{
		config = handle_arg(ac, av);
		if (!config)
			return (EXIT_FAILURE);
		if (init_arg(config) != 0)
			return (EXIT_FAILURE);
	}
	else
	{
		write(STDERR_FILENO, ARG_ERR, 33);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


//* ./philo [no. of philosopher] [time to die] [time to eat] [time to sleep] [no. of times each philosopher must eat] *
//TODO after stocking the settings, start creating the mutex.
//TODO create the forks (mutex)