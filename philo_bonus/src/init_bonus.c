/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:39:10 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/26 13:51:06 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "error_bonus.h"
#include "simulation_bonus.h"

static t_settings	*init_settings(int ac, char **av)
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
	config->done_eating = false;
	config->base_time = get_time();
	return (config);
}

int	init_bonus(int ac, char **av)
{
	t_philo		*philo;
	t_settings	*conf;

	if (argument_bonus(ac, av) == false)
		return (FAILED);
	conf = init_settings(ac, av);
	if (!conf)
		return (putendl_error(ALLOC_ERR));
	if (manage_mutex(conf) != SUCCEED)
		return (FAILED);
	philo = init_philo(conf);
	if (check_philo(philo, conf) != SUCCEED)
		return (FAILED);
	simulation_watcher(philo);
	end_sim(conf, philo);
	return (SUCCEED);
}
