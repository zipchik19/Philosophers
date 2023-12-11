/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:17 by ziharuty          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:19 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_prog	*prog;
	t_philo	*philo;
	pthread_mutex_t forks[MAX_PHILO];

	(void)philo;
	prog = NULL;
	prog = malloc(sizeof(t_prog));
	prog->philos = malloc(sizeof(t_philo));
	mainpars(argc, argv);
	init_prog(prog, prog->philos);
	mutexing(forks, ft_atoi(argv[1]));
	creating_philos(prog, prog->philos, forks, argv);
	threadding(prog, forks);
	destroying(NULL, prog, forks);
}