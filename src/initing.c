/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:08 by ziharuty          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:10 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	inputting(t_philo *philo, char **argv)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->must_eat = ft_atoi(argv[5]);
	else
		philo->must_eat = -1;
}

void	creat_phil(t_prog *prog, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].eaten = 0;
		prog->philos[i].iseatting = 0;
		inputting(&prog->philos[i], argv);
		prog->philos[i].starting_time = timing();
		prog->philos[i].last_meal = timing();
		prog->philos[i].dead_lock = &prog->dead_lock;
		prog->philos[i].write_lock = &prog->write_lock;
		prog->philos[i].meal_lock = &prog->meal_lock;
		prog->philos[i].deaddd = &prog->dead_flag;
		prog->philos[i].lfork = &forks[i];
		if (i == 0)
			prog->philos[i].rfork = &forks[prog->philos[i].num_of_philo - 1];
		else
			prog->philos[i].rfork = &forks[i - 1];
		i++;
	}
}

void	mutexing(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	init_prog(t_prog *prog, t_philo *philo)
{
	prog->philos = philo;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	return (0);
}
