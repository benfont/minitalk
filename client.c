/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:12:22 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/26 20:06:08 by aitlopez         ###   ########.fr       */
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
				write(1, "Erroa\n", 6);
				exit (-1);
			}
		}
		else
		{
			if (kill(pid_nb, SIGUSR2) == -1)
			{
				write(1, "Errob\n", 6);
				exit(-1);
			}
		}
		usleep(100);
		bit++;
	}
	write(1, "8", 1);
}

void	send_chars(int pid_nb, char **argv)
{
	int				cont;
	unsigned char	c;

	cont = 0;
	while (argv[2][cont] != '\0')
	{
		c = argv[2][cont];
		to_binary(pid_nb, c);
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
		write(2, "Error\nPlease type a PID number", 30);
		exit(-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid_nb;
	
	pid_nb = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "Error\nNo correct arguments", 26);
		return (0);
	}
	check_pid(argv);
	send_chars(pid_nb, &argv[2]);
	return (0);
}
