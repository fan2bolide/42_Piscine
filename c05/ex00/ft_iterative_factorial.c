/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:52:51 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/16 14:09:21 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int i;
	int factor;

	i = 1;
	factor = 1;
	while (i <= nb)
	{
		factor = factor * i;
		i++;
	}
	return factor;
}
