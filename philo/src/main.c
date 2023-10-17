/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:39:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/11 11:50:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "simulation.h"
#include "error_philo.h"

int	main(int ac, char **av)
{
	if ((ac < 5 || ac > 6) || valid_argument(ac, av) < 0)
		return (putendl_error(USG_ERR));
	else if (init_prog(ac, av) != SUCCEED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
