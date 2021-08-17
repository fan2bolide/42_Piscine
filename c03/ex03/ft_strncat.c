/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:12:29 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/11 17:12:30 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int size);

char	*ft_strncat(char *dest, char *src, unsigned int size)
{
	char	*destcpy;

	*destcpy = dest;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0 && size != 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (*destcpy);
}
