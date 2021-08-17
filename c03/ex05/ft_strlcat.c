/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:34:12 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/11 17:34:13 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				strlen(char *str);

int	main(void)
{
	
}

int	strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*destcpy;

	*destcpy = dest;
	if (size <= strlen(dest))
	{
		return (dest);
	}
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
	return (destcpy);
}
