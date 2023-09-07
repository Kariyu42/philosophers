/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:13:32 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/07 14:51:21 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "error.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	putendl_error(char *error)
{
	int	i;

	i = -1;
	while (error[++i])
		ft_putchar_fd(error[i], STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
