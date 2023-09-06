/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/06 19:40:07 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *philo, t_settings *conf)
{
	int	i;

	i = -1;
	philo = ft_calloc(conf->nbr_philo, sizeof(t_philo));
	while (++i < conf->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_nb = 0;
		philo[i].last_ate = 0;
		philo[i].conf = conf;
	}
	return (SUCCEED);
}

int	init_mutex(t_settings *conf)
{
	int	i;

	i = -1;
	conf->mutex = ft_calloc(conf->nbr_philo, sizeof(t_fork));
	while (++i < conf->nbr_philo)
	{
		conf->mutex[i].id = i + 1;
		if (pthread_mutex_init(&(conf->mutex[i].fork), NULL) != SUCCEED)
			return (EXIT_FAILURE);
	}
	return (SUCCEED);
}

void	set_up_configs(t_settings *config, int ac, char **av)
{
	config->nbr_philo = ft_atoi(av[1]);
	config->time_death = ft_atoi(av[2]);
	config->time_eat = ft_atoi(av[3]);
	config->time_sleep = ft_atoi(av[4]);
	if (ac == ADDL_ARG)
		config->food_limit = ft_atoi(av[5]);
	config->base_time = get_time();
}
