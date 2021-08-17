/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <bjeannot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:36:40 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/17 15:39:23 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	guess;

	guess = 1;
	while (guess != ((nb / guess) + guess) / 2 && guess * guess != nb)
		guess = ((nb / guess) + guess) / 2;
	if (guess * guess == nb)
		return (guess);
	return (0);
}
