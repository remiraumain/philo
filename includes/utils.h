/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:29:17 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 18:47:34 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

//	ERROR
void			ft_error(char *message);

//	STRING
unsigned int	my_strlen(char *string);
int				ft_custom_atoi(char *arg);

//	TIME
long			get_time_in_ms(void);

//	CLEANUP
void			clear(t_data *data);

#endif