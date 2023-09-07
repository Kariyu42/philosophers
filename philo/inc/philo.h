/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:37:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/07 13:43:30 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ---------------------------- libraries ------------------------------ */
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCEED 0
# define COR_ARG 5
# define ADDL_ARG 6

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct	s_settings
{
	int				nbr_philo;
	time_t			time_death;
	time_t			time_eat;
	time_t			time_sleep;
	int				food_limit;
	time_t			base_time;
	struct s_fork	*mutex;
}	t_settings;

typedef struct	s_philo
{
	struct s_settings	*conf;
	int					id;
	int					eat_nb;
	time_t				last_ate;
	pthread_t			thread;
}	t_philo;

/* ----------------------- init_func / time ------------------------- */
void	set_up_configs(t_settings *config, int ac, char **av);
time_t	get_time(void);
t_philo	*init_arg(t_settings *conf);
int		init_mutex(t_settings *conf);
int		init_philo(t_philo *philo, t_settings *conf);

/* ----------------------- addl tools -----------------------*/
void	*ft_calloc(size_t count, size_t size);
bool	is_numeric(char *nbr);
