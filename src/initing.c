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

int inputing(t_philo *philo, char **argv)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->time_to_die = ft_atoi(argv[1]);
	else
		philo->time_to_die = -1;
	return (1);
}

void 



int init_prog(t_prog prog, t_philo *philo)
{
	prog->dead_flag = 0;
	prog->philos = philo; 
	//initilize mutexes
}