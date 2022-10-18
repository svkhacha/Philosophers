/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:43:31 by svkhacha          #+#    #+#             */
/*   Updated: 2022/10/17 21:41:35 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_all_moves(t_philo *philo)
{
	pthread_mutex_t	philo_state;
	pthread_t		th;
	int				i;

	philo[0].prev_fork = &philo[philo[0].num_of_philos - 1].own_fork;
	pthread_mutex_init(&philo_state, NULL);
	pthread_mutex_lock(&philo_state);
	i = 0;
	while (i < philo[0].num_of_philos)
	{
		philo[i].philo_state = &philo_state;
		pthread_create(&th, NULL, philo_actions, &philo[i++]);
		pthread_detach(th);
	}
	if (philos_all_moves_2(philo) == 1)
		return ;
	pthread_mutex_lock(&philo_state);
	pthread_mutex_destroy(&philo_state);
	free(philo);
}

int	philos_all_moves_2(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i >= philo[i].num_of_philos)
			i = 0;
		if (checking_die(&philo[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	int		i;

	if (check_characters(argc, argv) == -1 || ft_atoi(argv[1]) == 0)
		return (-1);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!(philo))
		return (-1);
	i = 0;
	philo = initialization(philo, argc, argv, i);
	while (i < ft_atoi(argv[1]))
	{
		philo[i].start_time = sys_current_time();
		philo[i].last_eat_time = philo[i].start_time;
		i++;
	}
	philos_all_moves(philo);
	i = 0;
	while (i < philo[0].num_of_philos)
		pthread_mutex_destroy(&philo[i++].own_fork);
	return (0);
}
