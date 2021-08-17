/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:10:26 by njennes           #+#    #+#             */
/*   Updated: 2021/08/09 15:10:42 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		i = i + 1;
	}
	if (str[i] == 0)
		return (1);
	return (0);
}
