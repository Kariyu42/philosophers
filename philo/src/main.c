/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/10 10:04:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error_philo.h"

int	main(int ac, char **av)
{
	if (ac == COR_ARG || ac == ADDL_ARG)
	{
		if (init_prog(ac, av) != SUCCEED)
			return (EXIT_FAILURE);
	}
	else
	{
		putendl_error(ARG_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
