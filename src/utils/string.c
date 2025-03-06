/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:38:07 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/06 18:47:08 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	my_strlen(char *string)
{
	unsigned int	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

static int	convert_number(char *arg, unsigned int *i)
{
	int	res;

	res = 0;
	while (arg[*i] >= '0' && arg[*i] <= '9')
	{
		if (res > (res * 10 + (arg[*i] - '0')))
			return (-1);
		res = res * 10 + (arg[*i] - '0');
		(*i)++;
	}
	return (res);
}

int	ft_custom_atoi(char *arg)
{
	unsigned int	i;
	int				res;
	int				sign;

	i = 0;
	sign = 1;
	while (arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i] == '0')
		i++;
	res = convert_number(arg, &i);
	if (arg[i])
		return (-1);
	return (res * sign);
}
