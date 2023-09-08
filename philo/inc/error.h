/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/09/08 12:20:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* --- init message --- */
# define INIT_ERR "error: failed to initialize"
# define MUTEX_ERR "error: mutex creation failed"
# define LOCK_ERR "error: failed to lock mutex"
# define THREAD_ERR "error: thread creation failed"

/* --- parsing message --- */
# define ARG_ERR "error: wrong number of arguments"
# define USG_ERR "error: check the argument's format"

/* ----------------------- error ------------------------- */
void	putendl_error(char *error);