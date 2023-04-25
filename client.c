/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:12:22 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/25 21:17:37 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	to_binary(int pid_nb, char c)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << (7 - bit))) == 0)
		{
			if (kill(pid_nb, SIGUSR1) == -1)
			{
				write(1, "Error\n", 6);
				exit (-1);
			}
		}
		else
		{
			if (kill(pid_nb, SIGUSR2) == -1)
			{
				write(1, "Error\n", 6);
				exit (-1);
			}
		}
		usleep(100);
		bit++;
	}
}

int	send_chars(int pid_nb, char **argv)
{
	int		count;
	unsigned char	c;

	cont = 0;
	while (argv[2][cont])
	{
		c = argv[2][cont];
		to_binary(pid_nb, c)
		cont++;
	}
}

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
	int		pid_nb;

	if (argc != 3)
	{
		write(1, "Error\nNo correct arguments", 26);
		return (0);
	}
	check_pid(argv);
	pid_nb = atoi(argv[1]);
	send_chars(pid_nb, argv);
	return (0);
}
