/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/22 19:06:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

static t_philo	*init_philo(t_settings *conf)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = ft_calloc(conf->nbr_philo, sizeof(t_philo));
	while (++i < conf->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_nb = 0;
		philo[i].last_ate = 0;
		philo[i].conf = conf;
		if (pthread_create(&philo[i].thread, NULL, &routine, \
			&philo[i]) != 0)
			return (NULL);
	}
	return (philo);
}

int	init_mutex(t_settings *conf)
{
	int	i;

	i = -1;
	conf->fork = ft_calloc(conf->nbr_philo, sizeof(pthread_mutex_t));
	if (!conf->fork)
		return (ALLOC);
	while (++i < conf->nbr_philo)
		if (pthread_mutex_init(&(conf->fork[i]), NULL) != 0)
			return (FAILED);
	if (pthread_mutex_init(&conf->put_status, NULL) != 0 || \
		pthread_mutex_init(&conf->meal_lock, NULL) != 0 || \
		pthread_mutex_init(&conf->food_nbr, NULL) != 0 || \
		pthread_mutex_init(&conf->limit_lock, NULL) != 0)
		return (FAILED);
	return (SUCCEED);
}

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

int	init_prog(int ac, char **av)
{
	t_philo		*philo;
	t_settings	*conf;

	if (valid_argument(ac, av) == false)
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
