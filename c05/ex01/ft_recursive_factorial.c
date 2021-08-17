/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:52:59 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/16 14:09:01 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	int res;
	if (nb == 0)
	{
		return (1);
	}
	res = nb * ft_recursive_factorial(nb - 1);
	return res;
}
