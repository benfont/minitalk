/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:50:05 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/25 17:57:10 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_signals(int signal)
{
	int		c;


}

void	get_pid(void)
{
	int		pid;

	pid = getpid();
	if (!pid)
	{
		write(1, "Error\nThere is no PID code\n", 27);
		return (0);
	}
	put_nbr(pid);
}


/**
 * @brief 
 * 
 * envia el PID a otra terminal
 */
int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		write(1, "Error\nNo correct arguments", 26);
		return (0);
	}
	get_pid();
	return (0);
}
