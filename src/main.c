/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:18:39 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/11 14:07:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!parse(argc, argv, &data))
		return (STDERR_FILENO);
	if (!init(&data))
		return (STDERR_FILENO);
	if (!(argc == 6 && data.nb_meals == 0))
		simulation(&data);
	clear(&data);
	return (0);
}
