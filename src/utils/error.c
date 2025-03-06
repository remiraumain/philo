/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:25:38 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 21:42:27 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *message)
{
	unsigned int	len;

	len = my_strlen(message);
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, message, len);
	write(STDERR_FILENO, "\n", 1);
}
