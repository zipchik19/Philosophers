/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:19:04 by ziharuty          #+#    #+#             */
/*   Updated: 2023/12/06 13:19:06 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleepping(t_philo *philo)
{
	sleeping(philo->time_to_sleep);
	message("Philo is sleeping", philo, philo->id);
}

void	thinking(t_philo *philo)
{
	message("Philo is thinking", philo, philo->id);
}

void	eatting(t_philo *philo)
{
	pthread_mutex_lock(philo
	->rfork);
	message("Philo took the right fork", philo, philo->id);
	if (philo->num_of_philo == 1)
	{
		sleeping(philo->time_to_die);
		pthread_mutex_unlock(philo->rfork);
		return ;
	}
	pthread_mutex_lock(philo->lfork);
	message("Philo took the left fork", philo, philo->id);
	philo->iseatting = 1;
	pthread_mutex_lock(philo->meal_lock);
	message("Philo is eating", philo, philo->id);
	philo->last_meal = timing();
	philo->eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	sleeping(philo->time_to_eat);
	philo->iseatting = 0;
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);

}