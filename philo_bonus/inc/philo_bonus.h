/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:53:39 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/26 13:50:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* --- LIBRARIES --- */
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

/* --- MACROS --- */
# define SUCCEED 0
# define COR_ARG 5
# define ADDL_ARG 6

typedef struct s_settings
{
	int				nbr_philo;
	int				food_limit;
	bool			done_eating;
	time_t			time_death;
	time_t			time_eat;
	time_t			time_sleep;
	time_t			base_time;
}	t_settings;

typedef struct s_philo
{
	struct s_settings	*conf;
	int					id;
	int					eat_nb;
	time_t				last_ate;
}	t_philo;

/* --- PARSING --- */
int		init_bonus(int ac, char **av);
bool	argument_bonus(int ac, char **av);

/* --- TIME --- */
time_t	get_time(void);
time_t	timestamp(time_t origin, time_t current);

#endif