/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:05:05 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/12 14:20:12 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

bool	handle_arg(int ac, char **av, t_settings **conf, t_philo **philo)
{
		
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
