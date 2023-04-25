/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:12:22 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/18 18:22:21 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	check_pid(char **argv)
{
	int		count;

	count = 0;
	while (argv[1][count] >= '0' && argv[1][count] <= '9')
		count++;
	if (argv[1][count] != '\0')
	{
		write(1, "Error\nPlease type a PID number", 30);
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Error\nNo correct arguments", 26);
		return (0);
	}
	check_pid(argv);
	return (0);
}
