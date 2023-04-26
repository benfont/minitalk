/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:25:40 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/26 20:01:27 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(const char *str)
{
	int		count;
	int		sign;
	int		nb;

	count = 0;
	sign = -1;
	nb = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	if (str[count] == '+')
		count++;
	while (str[count] != '\0' && (str[count] >= '0' && str[count] <= '9'))
	{
		nb = (nb * 10) + (str[count] - '0');
		count++;
	}
	return (nb * sign);
}
