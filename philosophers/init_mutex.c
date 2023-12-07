/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:20 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:35:00 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_table *table)
{
	int		i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	if (!table->forks)
		return (0);
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], 0) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&table->general_mutex, 0) != 0)
		return (0);
	return (1);
}
