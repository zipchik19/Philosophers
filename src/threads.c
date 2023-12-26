/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:19:04 by ziharuty          #+#    #+#             */
/*   Updated: 2023/12/06 13:19:08 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	deadding(t_philo *philos)
{
	pthread_mutex_lock(philos->dead_lock);
	if (*philos->deaddd == 1)
		return (pthread_mutex_unlock(philos->dead_lock), 1);
	pthread_mutex_unlock(philos->dead_lock);
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		sleeping(1);
	while (!deadding(philo))
	{
		eatting(philo);
		sleepping(philo);
		thinking(philo);
	}
	return (ptr);
}

void	destroying(char *str, t_prog *prog, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	while (i < prog->philos->num_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(prog);
	free(prog->philos);
}

void	threadding(t_prog *prog, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	tmp;

	i = 0;
	if (pthread_create(&tmp, NULL, &checks_all, prog->philos) != 0)
		destroying("You have error while creating threads", prog, forks);
	while (i < prog->philos->num_of_philo)
	{
		if (pthread_create(&prog->philos[i].thread, NULL, \
		&routine, &prog->philos[i]) != 0)
			destroying("You have error while creating threads", prog, forks);
		i++;
	}
	i = 0;
	if (pthread_join(tmp, NULL) != 0)
		destroying("You have error while joining threads", prog, forks);
	while (i < prog->philos->num_of_philo)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			destroying("You have error while joining threads", prog, forks);
		i++;
	}
}
