/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:42:07 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/12 09:45:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	actions(t_philo *philo)
{
	int		running;
	int		finished;

	if (philo->id % 2 == 0)
	{
		print_action(philo, "is thinking");
		usleep(50);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->running_lock);
		running = philo->data->is_running;
		finished = philo->finished;
		pthread_mutex_unlock(&philo->data->running_lock);
		if (!running || finished)
			return ;
		delay_priority(philo);
		take_forks(philo);
		reset_priority(philo);
		eat(philo);
		drop_forks(philo);
		philo_sleep(philo);
		print_action(philo, "is thinking");
		usleep(100);
	}
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_unlock(philo->left_fork);
	}
	else
		actions(philo);
	return (NULL);
}

static int	check_philos(t_data *data, int *finished_count)
{
	int		finished;
	long	last_meal;
	long	max_time_last_meal;
	int		philo_in_danger;
	int		i;

	max_time_last_meal = 0;
	philo_in_danger = -1;
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philos[i].data_lock);
		last_meal = get_time_in_ms() - data->philos[i].last_meal_time;
		finished = data->philos[i].finished;
		pthread_mutex_unlock(&data->philos[i].data_lock);
		if (check_is_dead(data, &data->philos[i], finished, last_meal))
			return (0);
		if (!finished)
			set_if_in_danger(&data->philos[i], last_meal, &max_time_last_meal,
				&philo_in_danger);
		*finished_count += finished;
		i++;
	}
	set_priority(data, philo_in_danger);
	return (1);
}

static void	monitor(t_data *data)
{
	int		finished_count;

	while (1)
	{
		usleep(50);
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
