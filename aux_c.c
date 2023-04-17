/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:25:40 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/17 15:19:30 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	atoi_c(const char *str)
{
	int		count;
	int		sign;
	int		nb;

	count = 0;
	sign = -1;
	nb = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n')
		c++;
	if (str[c] == '-')
	{
		sign = -1;
		c++;
	}
	if (str[c] == '+')
		c++;
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		nb = (nb * 10) + (str[c] - '0')
		c++;
	}
	return (nb * sign);
}
