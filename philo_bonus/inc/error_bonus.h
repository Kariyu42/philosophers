/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:28:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/26 13:53:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

#include "philo_bonus.h"

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