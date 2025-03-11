/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:02 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 23:54:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

//	ACTIONS
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	died(t_philo *philo);

//	CHECKS
int		check_is_dead(t_data *data, t_philo *philo, int finished, long last_meal);
void	set_if_in_danger(t_philo *philo, long last_meal, long *max_time_last_meal, int *philo_in_danger);
void	set_priority(t_data *data, int philo_id);

//	PRINT
void	print_action(t_philo *philo, char *action);

//	PRIORITY
void	delay_priority(t_philo *philo);
void	reset_priority(t_philo *philo);

//	SIMULATION
void	simulation(t_data *data);

#endif