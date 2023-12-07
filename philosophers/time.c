/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:34:45 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:34:53 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval		tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 0.001));
}

unsigned long	time_calculator(unsigned long last)
{
	return (get_time() - last);
}

void	philo_sleep(int time_die)
{
	unsigned long	time;

	time = get_time() + time_die;
	while (get_time() <= time)
		usleep(100);
}
