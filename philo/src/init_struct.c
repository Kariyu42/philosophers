/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:27:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/17 08:41:25 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"

t_philo	*init_philo(t_settings *conf)
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
	conf->fork = malloc(sizeof(pthread_mutex_t) * conf->nbr_philo);
	while (++i < conf->nbr_philo)
	{
		if (pthread_mutex_init(&(conf->fork[i]), NULL) != 0)
			return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&conf->put_status, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&conf->meal_lock, NULL))
		return (EXIT_FAILURE);
	return (SUCCEED);
}
