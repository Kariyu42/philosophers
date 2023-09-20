/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:55:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/20 15:47:39 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"
#include "simulation.h"

static bool	death_sentence(time_t time, time_t last_ate, t_philo *philo)
{
	if (time - last_ate >= philo->conf->time_death)
		return (true);
	return (false);
}

static bool	all_philo_ate(t_philo *philo)
{
	long	total;
	t_philo	*tmp;
	long	i;

	i = 0;
	total = philo->conf->nbr_philo;
	tmp = philo;
	while (tmp)
	{
		// printf("tmp->eat_nb: %d\n", tmp->eat_nb);
		if (philo->conf->food_limit > 0 && \
			tmp->eat_nb >= philo->conf->food_limit)
			i++;
		if (i == total)
		{
			printf("total: %ld i:%ld\n", total, i);
			return (true);
		}
		tmp++;
	}
	return (false);
}

// watcher
int	simulation_watcher(t_philo *philo)
{
	long	exceed;
	time_t	time;
	long	i;

	ft_usleep(1000);
	if (philo->conf->nbr_philo == 1)
		return (0);
	i = 0;
	exceed = philo->conf->nbr_philo;
	while ("watcher")
	{
		time = timestamp(philo->conf->base_time, get_time());
		if (death_sentence(time, philo[i].last_ate, philo) == true)
		{
			printf("%ld %d died\n", time, philo[i].id);
			break ;
		}
		if (all_philo_ate(philo) == true)
			break ;
		i++;
		if (i == exceed)
			i = 0;
	}
	return (0);
}

static void	*lonely_routine(t_philo *philo)
{
	time_t	time;

	take_fork(philo, LEFT);
	put_routine(philo, philo->id, THINK);
	ft_usleep(philo->conf->time_death);
	time = timestamp(philo->conf->base_time, get_time());
	printf("%ld %d died\n", time, philo->id);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		put_routine(philo, philo->id, THINK);
		ft_usleep(philo->conf->time_death / 3);
	}
	if (philo->conf->nbr_philo == 1)
		return (lonely_routine(philo));
	while (1)
	{
		take_fork(philo, LEFT);
		take_fork(philo, RIGHT);
		eat(philo);
		put_routine(philo, philo->id, SLEEP);
		ft_usleep(philo->conf->time_sleep);
		put_routine(philo, philo->id, THINK);
		ft_usleep(philo->conf->time_death / 3);
	}
	return (NULL);
}
