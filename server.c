/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:50:05 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/28 19:22:27 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
/**
 * @brief Get the signals object
 * recibe y junta bytes enviados en formato binario
 * a traves de senales SIGUSR1 y SIGUSR2 
 * @param signal 
 */
void	get_signals(int signal)
{
	static int		bit = 0;
	static unsigned char	c = '\0';

	c = c << 1;
	if (signal == SIGUSR1)
	{
	}
	else
		c = c | 1;
	bit++;
	if (bit == 8)
	{

		write(1, &c, 1);
		bit = 0;
		c = '\0';
	}
}
/**
 * @brief Get the pid object
 * 
 */
void	get_pid(void)
{
	int		pid;

	pid = getpid();
	if (!pid)
	{
		write(1, "Error\nThere is no PID code\n", 27);
		exit(-1);
	}
	put_nbr(pid);
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(1, "Error\nNo correct arguments\n", 27);
		return (0);
	}
	get_pid();
	write(1, "\n", 1);
	signal(SIGUSR1, &get_signals);
	signal(SIGUSR2, &get_signals);
	while (1)
		sleep(1);
//		pause();
	return (0);
}
