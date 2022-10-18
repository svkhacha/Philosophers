/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:09:34 by svkhacha          #+#    #+#             */
/*   Updated: 2022/10/17 21:43:38 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*prev_fork;
	pthread_mutex_t	*philo_state;

	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_each_must_eat;
	int				eat_count;
	int				philo_id;
	int				*x;
	long			start_time;
	long			last_eat_time;
}					t_philo;

int		ft_atoi(char *str);
int		check_num_of_argc(int argc);
int		check_characters(int argc, char **argv);
long	sys_current_time(void);
void	my_usleep(int durartion);
void	odd_num_id(int id, float t);
void	print_output(t_philo *philo, char *str);
void	*philo_actions(void *p);
int		checking_die(void *p);
int		check_eating(t_philo *philo);
void	philos_all_moves(t_philo *philo);
int		philos_all_moves_2(t_philo *philo);
t_philo	*initialization(t_philo *philo, int argc, char **argv, int i);

#endif
