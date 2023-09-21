/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:37:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/21 16:57:27 by kquetat-         ###   ########.fr       */
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

/* --- STRUCT --- */
typedef struct s_settings
{
	int				nbr_philo;
	int				food_limit;
	bool			done_eating;
	time_t			time_death;
	time_t			time_eat;
	time_t			time_sleep;
	time_t			base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	put_status;
	pthread_mutex_t	limit_lock;
	pthread_mutex_t	food_nbr;
	pthread_mutex_t	meal_lock;
}	t_settings;

typedef struct s_philo
{
	struct s_settings	*conf;
	int					id;
	int					eat_nb;
	time_t				last_ate;
	pthread_t			thread;
}	t_philo;

/* --- INIT / TIME --- */
int		init_prog(int ac, char **av);
int		init_mutex(t_settings *conf);
bool	valid_argument(int ac, char **av);
time_t	get_time(void);
time_t	timestamp(time_t origin, time_t current);

/* --- TOOLS --- */
int		manage_mutex(t_settings *conf);
int		check_philo(t_philo *philo, t_settings *conf);
void	*ft_calloc(size_t count, size_t size);
bool	is_numeric(char *nbr);
int		ft_atoi(char *nbr);
int		ft_usleep(size_t milliseconds);

#endif