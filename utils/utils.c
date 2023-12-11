/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:39 by ziharuty          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:43 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	sleeping(size_t mlsec)
{
	size_t	start;

	start = timing();
	while (timing() - start < mlsec)
		usleep(500);
	return (0);
}

int	timing()
{
	struct timeval current_time;
	error(gettimeofday(&current_time, NULL), "Error while using gettimeofday");
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void error(int condition, char *str)
{
	if (condition)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		exit(1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
