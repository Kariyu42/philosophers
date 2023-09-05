/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/05 21:26:48 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(t_settings *conf)
{
	int			i;
	pthread_t	info;
	t_philo	*philo; //TODO tableau de philo:

	i = -1;
	philo = malloc(sizeof(t_philo) * conf->nbr_philo);
	if (!philo)
		return (EXIT_FAILURE);
	while (++i < conf->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_nb = 0;
		philo[i].last_ate = 0;
	}
	return (0);
}
