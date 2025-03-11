/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:26:52 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 23:43:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_dead(t_data *data, t_philo *philo, int finished, long last_meal)
{
	if (!finished && last_meal > data->time_to_die)
	{
		died(philo);
		return (1);
	}
	return (0);
}

void	set_if_in_danger(t_philo *philo, long last_meal, long *max_time_last_meal, int *philo_in_danger)
{
	if (last_meal > *max_time_last_meal)
	{
		*max_time_last_meal = last_meal;
		*philo_in_danger = philo->id;
	}
}
