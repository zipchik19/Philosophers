/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:20:21 by ziharuty          #+#    #+#             */
/*   Updated: 2023/12/15 17:20:23 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = timing() - philo->starting_time;
	if (!deadding(philo))
		printf("%zu, %d, %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	checking_ate(t_philo *philo)
{
	int	ardenkerac;
	int	i;

	ardenkerac = 0;
	i = 0;
	if (philo[0].must_eat == -1)
		return (0);
	while (i < philo[0].num_of_philo)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].must_eat <= philo[i].eaten)
			ardenkerac++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (ardenkerac == philo[0].num_of_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->deaddd = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

int	checking_died(t_philo *philo, size_t dye_time)
{
	pthread_mutex_lock(philo->meal_lock);
	if (timing() - philo->last_meal >= dye_time && philo->iseatting == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	checking_any_died(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philo)
	{
		if (checking_died(&philos[i], philos[i].time_to_die))
		{
			message("Philo died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->deaddd = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*checks_all(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	while (1)
		if (checking_ate(philo) == 1 || checking_any_died(philo) == 1)
			break ;
	return (ptr);
}
