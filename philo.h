/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:50:16 by ziharuty          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:32 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#define MAX_PHILO 300
#include <pthread.h>
#include <unistd.h>
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>


typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			must_eat;

	size_t		time_to_die;
	size_t		time_to_sleep;
	size_t		time_to_eat;
	size_t		starting_time;
	size_t		last_meal;
	int			num_of_philo;
	pthread_t	*rfork;
	pthread_t	*lfork;
}	t_philo;

typedef struct s_prog
{
	int		dead_flag;
	t_philo	*philos;
}	t_prog;


int init(t_philo *philo, char **argv);
int	mainpars (t_philo *philo, int argc, char **argv);
int check_args(char *str);


int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	error(int condition, char *str);


#endif
