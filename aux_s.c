/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:26:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/17 15:18:36 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int nb)
{
	if (nb >= 10)
	{
		put_nb(nb / 10);
		nb = nb % 10;
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
}
