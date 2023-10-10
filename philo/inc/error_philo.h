/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/10/10 10:01:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_PHILO_H
# define ERROR_PHILO_H

# include "philo.h"

/* --- MACRO --- */
# define ALLOC 1

/* --- ERROR MESSAGE --- */
# define NO_PHILO_ERR "error: missing philosopher(s)"
# define ALLOC_ERR "error: failed to allocate memory"
# define INIT_ERR "error: failed to initialize"
# define MUTEX_ERR "error: mutex creation failed"
# define LOCK_ERR "error: failed to lock mutex"
# define UNLOCK_ERR "error: failed to unlock mutex"
# define THREAD_ERR "error: thread creation failed"

/* --- PARSING --- */
# define ARG_ERR "error: wrong number of arguments"
# define USG_ERR "error: check the argument's format"

/* --- ERROR --- */
int	putendl_error(char *error);

#endif