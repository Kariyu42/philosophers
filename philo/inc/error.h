/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/17 09:10:56 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
#include "philo.h"

/* --- init message --- */
# define INIT_ERR "error: failed to initialize"
# define MUTEX_ERR "error: mutex creation failed"
# define LOCK_ERR "error: failed to lock mutex"
# define UNLOCK_ERR "error: failed to unlock mutex"
# define THREAD_ERR "error: thread creation failed"

/* --- parsing message --- */
# define ARG_ERR "error: wrong number of arguments"
# define USG_ERR "error: check the argument's format"

/* ----------------------- error ------------------------- */
void	putendl_error(char *error);

#endif