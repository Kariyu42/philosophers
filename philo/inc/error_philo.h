/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/18 17:20:33 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_PHILO_H
# define ERROR_PHILO_H

# include "philo.h"

/* --- MACRO --- */
# define ALLOC 1
# define MUTEX 2

/* --- ERROR MESSAGE --- */
# define NO_PHILO_ERR "error: missing philosopher(s)"
# define ALLOC_ERR "error: failed to allocate memory"
# define INIT_ERR "error: failed to initialize"
# define MUTEX_ERR "error: mutex creation failed"
# define LOCK_ERR "error: failed to lock mutex"
# define UNLOCK_ERR "error: failed to unlock mutex"
# define THREAD_ERR "error: thread creation failed"
# define JOIN_ERR "error: pthread_join failure"
# define DESTROY_ERR "error: mutex destroy failed"

/* --- PARSING --- */
# define ARG_ERR "error: wrong number of arguments"
# define USG_ERR "error: check the argument's format"

/* --- ERROR --- */
int	putendl_error(char *error);

#endif