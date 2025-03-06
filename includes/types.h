/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:22:50 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 21:41:38 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "philo.h"

typedef struct s_philo
{
	int				id;
	int				finished;
	int				meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	data_lock;
	int				philo_lock_init;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				is_running;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	long			start_time;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	running_lock;
	int				data_lock_init;
	int				thread_init;
}	t_data;

#endif