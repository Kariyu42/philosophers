/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 17:15:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error_philo.h"
#include "simulation.h"

static t_philo	*init_philo(t_settings *conf)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * conf->nbr_philo);
	if (!philo)
		return (NULL);
	while (++i < conf->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_nb = 0;
		philo[i].last_ate = 0;
		philo[i].conf = conf;
		if (pthread_mutex_init(&philo[i].eat_lock, NULL) != 0)
			return (NULL);
	}
	return (philo);
}

int	init_mutex(t_settings *conf)
{
	int	i;

	i = -1;
	conf->fork = malloc(sizeof(pthread_mutex_t) * conf->nbr_philo);
	if (!conf->fork)
		return (ALLOC);
	while (++i < conf->nbr_philo)
		if (pthread_mutex_init(&(conf->fork[i]), NULL) != 0)
			return (MUTEX);
	i = -1;
	while (++i < NBR_MUTEXES)
		if (pthread_mutex_init(&(conf->mute[i]), NULL) != 0)
			return (MUTEX);
	return (SUCCEED);
}

int	mutex_handler(t_settings *conf)
{
	int	err_type;

	err_type = init_mutex(conf);
	if (err_type == ALLOC)
		return (putendl_error(ALLOC_ERR));
	else if (err_type == MUTEX)
		return (putendl_error(MUTEX_ERR));
	return (SUCCEED);
}

static t_settings	*init_table(int ac, char **av)
{
	t_settings	*config;

	config = malloc(sizeof(t_settings));
	if (!config)
		return (NULL);
	config->nbr_philo = ft_atoi(av[1]);
	config->time_death = ft_atoi(av[2]);
	config->time_eat = ft_atoi(av[3]);
	config->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		config->food_limit = ft_atoi(av[5]);
	else
		config->food_limit = 0;
	config->done_eating = false;
	config->death = false;
	config->base_time = get_time();
	return (config);
}

int	init_prog(int ac, char **av)
{
	t_philo		*philo;
	t_settings	*conf;

	conf = init_table(ac, av);
	if (!conf)
		return (putendl_error(ALLOC_ERR));
	philo = init_philo(conf);
	if (!philo)
		return (putendl_error(ALLOC_ERR));
	if (mutex_handler(conf) != SUCCEED)
		return (putendl_error(MUTEX_ERR));
	if (watcher(philo) != 0 || end_sim(conf, philo) != 0)
		return (-1);
	return (SUCCEED);
}
