/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:37:46 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/17 14:37:51 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	nb;
	int	moins;

	nb = 0;
	moins = 1;
	while (*str != '+' && *str != '-' && *str < 33)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			moins *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + ((int)*str - '0');
		str++;
	}
	return (nb * moins);
}
