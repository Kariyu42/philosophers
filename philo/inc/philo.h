/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:37:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 14:23:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* --- LIBRARIES --- */
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/* --- MACRO --- */
# define SUCCEED 0
# define COR_ARG 5
# define ADDL_ARG 6
# define NBR_MUTEXES 3

/* --- ENUM --- */
typedef enum e_lock
{
	PRINT,
	STATUS,
	LAST_ATE,
}	t_lock;

/* --- STRUCT --- */
typedef struct s_settings
{
	int				nbr_philo;
	int				food_limit;
	bool			death;
	bool			done_eating;
	time_t			time_death;
	time_t			time_eat;
	time_t			time_sleep;
	time_t			base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mute[NBR_MUTEXES];
}	t_settings;

typedef struct s_philo
{
	int					id;
	int					eat_nb;
	time_t				last_ate;
	pthread_mutex_t		eat_lock;
	pthread_t			thread;
	struct s_settings	*conf;
}	t_philo;

/* --- INIT / TIME --- */
int		init_prog(int ac, char **av);
int		init_mutex(t_settings *conf);
int		valid_argument(int ac, char **av);
time_t	get_time(void);
time_t	time_now(time_t origin, time_t current);

/* --- TOOLS --- */
bool	is_numeric(char *nbr);
int		ft_atoi(char *nbr);
int		ft_usleep(size_t milliseconds);
void	end_sim(t_settings *conf, t_philo *philo);

#endif