/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:26:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/28 17:40:23 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
/**
 * @brief 
 * 
 * @param nb 
 */
void	put_nbr(int nb)
{
	if (nb >= 10)
	{
		put_nbr(nb / 10);
		nb = nb % 10;
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
