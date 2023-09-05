/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:37:36 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/05 21:34:00 by kquetat-         ###   ########.fr       */
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
# define ARG_ERR "error: wrong number of arguments\n"
# define USG_ERR "error: check the argument's format\n"

typedef struct	s_philo
{
	struct s_settings	*conf;
	int					id;
	int					eat_nb;
	time_t				last_ate;
}	t_philo;

typedef struct	s_settings
{
	int				nbr_philo;
	time_t			time_death;
	time_t			time_eat;
	time_t			time_sleep;
	int				food_limit;
	time_t			base_time;
	pthread_mutex_t	fork;
}	t_settings;

/* ----------------------- init_func / time ------------------------- */
void	set_up(t_settings *config, int ac, char **av);
time_t	get_time(void);
int		init_arg(t_settings *conf);

/* ----------------------- check_arg / ft_atoi ------------------------- */
bool	is_numeric(char *nbr);

