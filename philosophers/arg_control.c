/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <yozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:33:54 by yozcan            #+#    #+#             */
/*   Updated: 2023/07/04 12:35:03 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_digit(char **str)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_control(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf ("Number of invalid arguments!");
		return (0);
	}
	if (!ft_digit(argv))
	{
		printf ("Invalid character!");
		return (0);
	}
	return (1);
}
