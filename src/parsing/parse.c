/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:21:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 18:50:09 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_args_to_data(int arg, int index, t_data *data)
{
	if (index == 1)
		data->nb_philos = arg;
	else if (index == 2)
		data->time_to_die = arg;
	else if (index == 3)
		data->time_to_eat = arg;
	else if (index == 4)
		data->time_to_sleep = arg;
	else if (index == 5)
		data->nb_meals = arg;
}

static int	set_args(char **av, t_data *data)
{
	int	arg;
	int	i;

	i = 1;
	while (av[i])
	{
		arg = ft_custom_atoi(av[i]);
		if (arg < 0)
		{
			ft_error("args must be positive numbers (0 to max int)");
			return (0);
		}
		add_args_to_data(arg, i, data);
		i++;
	}
	return (1);
}

int	parse(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		ft_error("invalid args: ./philo nb_philos time_to_die time_to_eat \
		time_to_sleep [nb_meals]");
		return (0);
	}
	if (!set_args(argv, data))
		return (0);
	if (data->nb_philos < 1)
	{
		ft_error("must have at least one philosopher");
		return (0);
	}
	return (1);
}
