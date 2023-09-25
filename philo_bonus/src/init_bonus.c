/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:39:10 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/25 07:48:45 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "error_bonus.h"
#include "simulation_bonus.h"

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
