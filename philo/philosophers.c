/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:50:51 by svkhacha          #+#    #+#             */
/*   Updated: 2022/10/17 21:41:54 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*initialization(t_philo *philo, int argc, char **argv, int i)
{
	philo[0].x = malloc(sizeof(int *));
	*(philo[0].x) = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&philo[i].own_fork, NULL);
		if (i == 0)
			philo[i].prev_fork = NULL;
		else
			philo[i].prev_fork = &philo[i - 1].own_fork;
		philo[i].num_of_philos = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		philo[i].start_time = 0;
		if (argc == 6)
			philo[i].times_each_must_eat = ft_atoi(argv[5]);
		else
			philo[i].times_each_must_eat = -1;
		philo[i].last_eat_time = 0;
		philo[i].eat_count = 0;
		philo[i].philo_id = i + 1;
		philo[i].x = philo[0].x;
		i++;
	}
	return (philo);
}

int	checking_die(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (sys_current_time() - philo->last_eat_time
		> philo->time_to_die)
	{
		if (*philo->x == 0)
		{
			printf("%lu: Philosopher %d" ANSI_COLOR_RED " died 💀\n"
				ANSI_COLOR_RESET, sys_current_time() - philo->start_time,
				philo->philo_id);
			*philo->x = 1;
			return (1);
		}
		pthread_mutex_unlock(philo->philo_state);
		return (1);
	}
	else if (philo->times_each_must_eat != -1
		&& philo->times_each_must_eat <= philo->eat_count)
	{
		if (check_eating(philo) == 1)
			return (1);
	}
	return (0);
}

int	check_eating(t_philo *philo)
{
	my_usleep(philo->philo_id);
	if (philo[0].times_each_must_eat > -1)
	{
		if (*philo->x == 0)
		{
			printf(ANSI_COLOR_MAGENTA "Every philosopher has eaten enough 👌"
				ANSI_COLOR_RESET "\n");
				*philo->x = 1;
		}
	}
	return (1);
}

void	*philo_actions(void *p)
{
	t_philo		*philo;

	philo = (t_philo *) p;
	odd_num_id(philo->philo_id, philo->time_to_eat);
	while (philo->times_each_must_eat == -1
		|| philo->eat_count < philo->times_each_must_eat)
	{
		pthread_mutex_lock(&philo->own_fork);
		print_output(philo, ANSI_COLOR_CYAN "has taken a fork 🍴"
			ANSI_COLOR_RESET);
		pthread_mutex_lock(philo->prev_fork);
		print_output(philo, ANSI_COLOR_CYAN "has taken a fork 🍴"
			ANSI_COLOR_RESET);
		philo->last_eat_time = sys_current_time();
		print_output(philo, ANSI_COLOR_GREEN "is eating 🍝"
			ANSI_COLOR_RESET);
		my_usleep(philo->time_to_eat);
		pthread_mutex_unlock(&philo->own_fork);
		pthread_mutex_unlock(philo->prev_fork);
		philo->eat_count++;
		print_output(philo, ANSI_COLOR_BLUE "is sleeping 😴" ANSI_COLOR_RESET);
		my_usleep(philo->time_to_sleep);
		print_output(philo, ANSI_COLOR_YELLOW "is thinking 🤔" ANSI_COLOR_RESET);
	}
	return (NULL);
}
