/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:48 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:34:52 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_status(t_table *table, int i, char *str)
{
	if (!real_death(table) || !necessary_eating(table, i))
	{
		pthread_mutex_unlock(&table->forks[i]);
		pthread_mutex_unlock(&table->forks[(i + 1) % table->philo_nbr]);
		return (0);
	}
	pthread_mutex_lock(&table->general_mutex);
	printf ("%-10lu %d %s\n", time_calculator(table->start_time),
		table->philos[i]->philo_id, str);
	pthread_mutex_unlock(&table->general_mutex);
	return (1);
}
