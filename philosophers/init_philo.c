/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:24 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:34:59 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_table *table)
{
	int		i;

	i = 0;
	table->philos = malloc(sizeof(t_philo *) * table->philo_nbr);
	if (!table->philos)
		return (0);
	table->death_philo = 0;
	table->thread_index = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i] = malloc(sizeof(t_philo));
		if (!table->philos[i])
			return (0);
		table->philos[i]->philo_id = i + 1;
		table->philos[i]->eat_count = 0;
		table->philos[i]->last_eat_time = get_time();
		i++;
	}
	return (1);
}
