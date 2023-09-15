/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:05:05 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/16 04:38:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

t_settings	*handle_settings(int ac, char **av)
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
	config->base_time = get_time();
	return (config);
}

bool	valid_argument(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (is_numeric(av[i]) == false)
		{
			putendl_error(USG_ERR);
			return (false);
		}
	}
	if (ft_atoi(av[1]) < 1)
		return (false);
	return (true);
}
