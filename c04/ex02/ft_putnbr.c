/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <bjeannot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:14:23 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/19 11:16:06 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_modulo(int a, int b)
{
	while (a > b)
	{
		a = a - b;
	}
	return (a);
}

void	ft_print(long nb, long modulo)
{
	char	letter;
	long	result;

	letter = '0';
	result = 0;
	while (nb >= modulo)
	{
		nb = nb - modulo;
		result = result + 1;
	}
	letter = letter + result;
	write(1, &letter, 1);
	if (modulo > 1)
		ft_print(nb, modulo / 10);
}

void	ft_putnbr(int nb)
{
	char	c;
	long	modulo;
	long	nbcpy;

	nbcpy = nb;
	if (nbcpy < 0)
	{
		write(1, "-", 1);
		nbcpy = nbcpy * -1;
	}
	if (nbcpy < 10)
	{
		c = '0';
		c = c + nbcpy;
		write(1, &c, 1);
	}
	else
	{
		modulo = 10;
		while (modulo <= nbcpy)
			modulo = modulo * 10;
		modulo = modulo / 10;
		ft_print(nbcpy, modulo);
	}
}
