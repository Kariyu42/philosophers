/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:05:05 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/07 22:09:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

bool	handle_arg(int ac, char **av, t_settings **conf, t_philo **philo)
{
	*conf = ft_calloc(1, sizeof(t_settings));
	set_up_configs(*conf, ac, av);
	if (init_mutex(*conf) != SUCCEED)
	{
		putendl_error(MUTEX_ERR);
		return (false);
	}
	if (init_philo(*philo, *conf) != SUCCEED)
	{
		putendl_error(THREAD_ERR);
		return (false);
	}
	return (true);
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
