/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:06:36 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 21:42:46 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->thread_init)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

static void	clear_mutex(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		if (philo->philo_lock_init == 1)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&philo->data_lock);
		}
		i++;
	}
	if (data->data_lock_init == 1)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->running_lock);
	}
}

static void	free_memory(t_data *data)
{
	if (data->philos != NULL)
	{
		free(data->philos);
		data->philos = NULL;
	}
	if (data->forks != NULL)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

void	clear(t_data *data)
{
	if (!data)
		return ;
	join_philosophers(data);
	clear_mutex(data);
	free_memory(data);
	memset(data, 0, sizeof(t_data));
}
