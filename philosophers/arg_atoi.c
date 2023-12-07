/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:29:14 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:35:04 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int				i;
	long long int	result;

	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == ' ' || str[i] == 'f')
		i++;
	while (str[i])
	{
		result = (result * 10) + (str[i] - 48);
		if (result > 2147483647 || result < -2147483647)
			return (-1);
		i++;
	}
	return (result);
}

int	detail_control(t_table *table)
{
	if (table->philo_nbr == -1 || table->time_die == -1
		|| table->time_eat == -1 || table->time_slp == -1
		|| table->mand_eat_count == -1)
	{
		printf("Argument is outside the desired integer range!");
		return (0);
	}
	if (table->philo_nbr == 0)
		return (0);
	if (table->time_die == 0)
	{
		printf ("0 1 died");
		return (0);
	}
	return (1);
}

int	arg_atoi(int ac, char **av, t_table *table)
{
	int	temp;

	temp = 0;
	table->philo_nbr = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_slp = ft_atoi(av[4]);
	if (ac == 6)
	{
		temp = ft_atoi(av[5]);
		if (temp == 0)
			return (0);
		else
			table->mand_eat_count = temp;
	}
	else
		table->mand_eat_count = -2;
	if (!detail_control(table))
		return (0);
	return (1);
}
