/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:42:07 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 21:41:59 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philo	*philo;
	int		running;
	int		finished;

	philo = (t_philo *)arg;
	print_action(philo, "is thinking");
	if (philo->id % 2 == 0)
		usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->data->running_lock);
		running = philo->data->is_running;
		finished = philo->finished;
		pthread_mutex_unlock(&philo->data->running_lock);
		if (!running || finished)
			return (NULL);
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
		print_action(philo, "is thinking");
		usleep(75);
	}
}

static int	check_philos(t_data *data, int *finished_count)
{
	int		finished;
	long	last_meal;
	int		i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].data_lock);
		last_meal = get_time_in_ms() - data->philos[i].last_meal_time;
		finished = data->philos[i].finished;
		pthread_mutex_unlock(&data->philos[i].data_lock);
		if (!finished && last_meal > data->time_to_die)
		{
			died(&data->philos[i]);
			return (0);
		}
		*finished_count += finished;
		i++;
	}
	return (1);
}

static void	monitor(t_data *data)
{
	int		finished_count;

	while (1)
	{
		finished_count = 0;
		if (!check_philos(data, &finished_count))
			return ;
		if (finished_count == data->nb_philos)
		{
			pthread_mutex_lock(&data->running_lock);
			data->is_running = 0;
			pthread_mutex_unlock(&data->running_lock);
			return ;
		}
		usleep(100);
	}
}

void	simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	data->is_running = 1;
	data->start_time = get_time_in_ms();
	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->last_meal_time = get_time_in_ms();
		if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
		{
			pthread_mutex_lock(&data->running_lock);
			data->is_running = 0;
			pthread_mutex_unlock(&data->running_lock);
			data->thread_init = i;
			ft_error("error creating philo thread");
			return ;
		}
		i++;
	}
	data->thread_init = i;
	monitor(data);
}
