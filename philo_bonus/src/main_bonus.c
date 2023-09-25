/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:53:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/25 07:39:54 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "error_bonus.h"

int	main(int ac, char **av)
{
	if (ac == COR_ARG || ac == ADDL_ARG)
	{
		if (init_bonus(ac, av) != SUCCEED)
			return (EXIT_FAILURE);
	}
	else
	{
		putendl_error(ARG_ERR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
