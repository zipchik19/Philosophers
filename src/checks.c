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

	ardenkearc = 0;
	i = 0;
	if (philo->must_eat == -1)
		return (0);
	while (i < philo[0]->num_of_philo)
	{
		pthread_mutex_lock(philo[i]->meal_lock);
		if (philo[i]->must_eat <= philo[i]->eaten)
			ardenkerac++;
		pthread_mutex_unlock(philo[i]->meal_lock);
		i++:
	}
	if (ardenkerac == philo->num_of_philo)
	{
		pthread_mutex_lock(philo[i]->dead_lock);
		*philo->deaddd = 1;
		pthread_mutex_unlock(philo[i]->dead_lock);
		return (1);
	}
	return (0);
}

int checking_died(t_philo *philo)
{
	if 
}