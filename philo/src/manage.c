/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:01:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/21 17:12:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

// void	end_sim(t_settings *conf, t_philo *philo)
// {
	
// }

int	check_philo(t_philo *philo, t_settings *conf)
{
	int	i;

	i = -1;
	if (!philo)
	{
		while (++i < conf->nbr_philo)
			pthread_mutex_destroy(&(conf->fork[i]));
		pthread_mutex_destroy(&conf->put_status);
		pthread_mutex_destroy(&conf->meal_lock);
		pthread_mutex_destroy(&conf->food_nbr);
		free(conf->fork);
		free(conf);
		return (putendl_error(THREAD_ERR));
	}
	return (SUCCEED);
}

int	manage_mutex(t_settings *conf)
{
	int	err_type;

	err_type = init_mutex(conf);
	if (err_type == ALLOC)
		return (putendl_error(ALLOC_ERR));
	else if (err_type == FAILED)
	{
		free(conf);
		return (putendl_error(MUTEX_ERR));
	}
	return (SUCCEED);
}
