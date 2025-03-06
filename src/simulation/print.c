/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:05:45 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 18:38:29 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->print_lock);
	pthread_mutex_lock(&philo->data->running_lock);
	if (philo->data->is_running)
		printf("%ld %d %s\n", get_time_in_ms() \
		- philo->data->start_time, philo->id, action);
	pthread_mutex_unlock(&philo->data->running_lock);
	pthread_mutex_unlock(&philo->data->print_lock);
}
