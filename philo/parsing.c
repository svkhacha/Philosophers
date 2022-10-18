/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:24:20 by svkhacha          #+#    #+#             */
/*   Updated: 2022/10/15 18:45:20 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (sign * result);
}

int	check_num_of_argc(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "❌ Error: Invalid number of arguments\n", 39);
		return (-1);
	}
	return (0);
}

int	check_characters(int argc, char **argv)
{
	int	i;
	int	j;

	if (check_num_of_argc(argc))
		return (-1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(2, "❌ Error: Invalid characters appeared\n", 40);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_output(t_philo *philo, char *str)
{
	printf("%ld: Philosopher %d %s\n",
		sys_current_time() - philo->start_time,
		philo->philo_id, str);
}
