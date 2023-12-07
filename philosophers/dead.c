/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:02 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:35:02 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philos_eating(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (!necessary_eating(table, i))
			return (0);
		i++;
	}
	return (1);
}

int	dead_philo(t_table *table, int index)
{
	unsigned long	time;

	pthread_mutex_lock(&table->general_mutex);
	time = time_calculator(table->philos[index]->last_eat_time);
	if (time >= (unsigned long)table->time_die
		&& !(table->philos[index]->eat_count == table->mand_eat_count))
	{
		printf ("%-10lu   %d %s\n", time,
			table->philos[index]->philo_id, "died");
		table->death_philo = 1;
		pthread_mutex_unlock(&table->general_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->general_mutex);
	return (0);
}

void	*dead(void *data)
{
	t_table		*table;
	int			i;

	table = (t_table *)data;
	while (1)
	{
		i = 0;
		if (!real_death(table) || !all_philos_eating(table))
			break ;
		while (i < table->philo_nbr)
		{
			if (!all_philos_eating(table) || dead_philo(table, i))
				break ;
			i++;
		}
	}
	return (NULL);
}
