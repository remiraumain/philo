/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:02 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 20:43:30 by rraumain         ###   ########.fr       */
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

//	PRINT
void	print_action(t_philo *philo, char *action);

//	SIMULATION
void	simulation(t_data *data);

#endif