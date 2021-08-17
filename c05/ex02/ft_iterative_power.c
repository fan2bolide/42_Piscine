/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:08:27 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/16 14:28:34 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return res;
}
