/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:12:21 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/11 14:51:56 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delay_priority(t_philo *philo)
{
	int	running;
	int	priority_id;

	pthread_mutex_lock(&philo->data->running_lock);
	running = philo->data->is_running;
	pthread_mutex_unlock(&philo->data->running_lock);
	pthread_mutex_lock(&philo->data->priority_lock);
	priority_id = philo->data->priority_id;
	pthread_mutex_unlock(&philo->data->priority_lock);
	if (priority_id == -1 || priority_id == philo->id || !running)
		return ;
	usleep(50);
}

void	reset_priority(t_philo *philo)
{
	int	priority_id;

	pthread_mutex_lock(&philo->data->priority_lock);
	priority_id = philo->data->priority_id;
	pthread_mutex_unlock(&philo->data->priority_lock);
	if (priority_id == philo->id)
	{
		pthread_mutex_lock(&philo->data->priority_lock);
		if (philo->data->priority_id == philo->id)
			philo->data->priority_id = -1;
		pthread_mutex_unlock(&philo->data->priority_lock);
	}
}

void	set_priority(t_data *data, int philo_id)
{
	pthread_mutex_lock(&data->priority_lock);
	data->priority_id = philo_id;
	pthread_mutex_unlock(&data->priority_lock);
}
