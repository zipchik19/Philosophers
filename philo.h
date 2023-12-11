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

#include <pthread.h>
#include <unistd.h>
# include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

# define MAX_PHILO 300

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			must_eat;
	int			num_of_philo;
	int			eaten;
	int			iseatting;
	int			*deaddd;
	size_t		time_to_die;
	size_t		time_to_sleep;
	size_t		time_to_eat;
	size_t		starting_time;
	size_t		last_meal;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;

}	t_philo;

typedef struct s_prog
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	think_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}					t_prog;

void	creating_philos(t_prog *prog, t_philo *philos, pthread_mutex_t *forks, char **argv);
void	destroying(char *str, t_prog *prog, pthread_mutex_t *forks);
void	mutexing(pthread_mutex_t *forks, int philo_num);
void	inputting(t_philo *philo, char **argv);
void	threadding(t_prog *prog, pthread_mutex_t *forks);
void	*routine(void *ptr);
void	mainpars(int argc, char **argv);
void	message(char *str, t_philo *philo, int id);
void	eatting(t_philo *philo);
void	sleepping(t_philo *philo);
void	thinking(t_philo *philo);

int	deadding(t_philo *philo);
int	check_args(char *str);
int	init_prog(t_prog *prog, t_philo *philo);

int		sleeping(size_t mlsec);
int		timing();
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	error(int condition, char *str);


#endif
