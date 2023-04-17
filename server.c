/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:50:05 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/17 15:15:40 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
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
}
