/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:13 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:35:01 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	int		i;

	i = 0;
	if (!table)
		return ;
	if (table->forks != NULL)
		free(table->forks);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free (table->philos);
	}
	free (table);
}
