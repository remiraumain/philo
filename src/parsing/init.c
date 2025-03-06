/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:47:30 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 21:43:28 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(int i, t_philo *philo, t_data *data)
{
	philo->id = i + 1;
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[(i + 1) % data->nb_philos];
	philo->last_meal_time = 0;
	philo->meals_eaten = 0;
	philo->finished = 0;
	philo->data = data;
	philo->philo_lock_init = 0;
	if (pthread_mutex_init(&data->forks[i], NULL) != 0)
	{
		ft_error("Failed to initialize fork mutex");
		return (0);
	}
	if (pthread_mutex_init(&philo->data_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->forks[i]);
		ft_error("Failed to initialize philo data mutex");
		return (0);
	}
	philo->philo_lock_init = 1;
	return (1);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (!init_philo(i, &data->philos[i], data))
			return (0);
		i++;
	}
	return (1);
}

static int	init_data_mutex(t_data *data)
{
	data->data_lock_init = 0;
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
		ft_error("Failed to initialize print mutex");
		return (0);
	}
	if (pthread_mutex_init(&data->running_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		ft_error("Failed to initialize running mutex");
		return (0);
	}
	data->data_lock_init = 1;
	return (1);
}

int	init(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
	{
		ft_error("forks allocation failed");
		return (0);
	}
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
	{
		free(data->forks);
		ft_error("philos allocation failed");
		return (0);
	}
	if (!init_philos(data) || !init_data_mutex(data))
	{
		clear(data);
		return (0);
	}
	return (1);
}
