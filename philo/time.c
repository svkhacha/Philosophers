/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:54:06 by svkhacha          #+#    #+#             */
/*   Updated: 2022/10/15 18:48:29 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	sys_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000
		+ current_time.tv_usec / 1000);
}

void	my_usleep(int duration)
{
	long	time;

	time = sys_current_time();
	while (sys_current_time() < time + duration)
		usleep(duration);
}

void	odd_num_id(int id, float t)
{
	float	float_num;

	float_num = t * 0.9;
	if (id % 2 != 0)
		my_usleep(float_num);
}
