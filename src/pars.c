/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:24 by ziharuty          #+#    #+#             */
/*   Updated: 2023/11/25 19:09:26 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_args(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	mainpars (int argc, char **argv)
{
	error((argc != 5 && argc != 6), "Your written arguments is not enough or more than enough");
	error(ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > MAX_PHILO || check_args(argv[1]), "Something wrong with the philo's number");
	error(ft_atoi(argv[2]) < 0 || check_args(argv[1]), "Invalid time to die value");
	error(ft_atoi(argv[3]) < 0 || check_args(argv[1]), "Invalid time to eat value");
	error(ft_atoi(argv[4]) < 0 || check_args(argv[1]), "Invalid time to sleep value");
	error(argv[5] && (ft_atoi(argv[4]) < 0 || check_args(argv[1])), "Invalid time to philo must eat value");
}
