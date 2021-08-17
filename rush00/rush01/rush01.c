/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdevigne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:27:21 by fdevigne          #+#    #+#             */
/*   Updated: 2021/08/07 14:31:36 by fdevigne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_line(int x, char s[5], int token)
{
	int	l;
	int	f;

	if (token == 0)
	{
		token = 0;
		f = 2;
	}
	else
	{
		token = 2;
		f = 0;
	}
	l = x - 2;
	ft_putchar(s[token]);
	while (l-- > 0)
	{
		ft_putchar(s[1]);
	}
	if (x > 1)
	{
		ft_putchar(s[f]);
	}
	ft_putchar('\n');
}

void	ft_body(int x, int y, char s[5])
{
	int	l;

	l = x - 2;
	y = y - 2;
	while (y > 0)
	{
		ft_putchar(s[4]);
		if (x > 1)
		{
			while (l-- > 0)
			{
				ft_putchar(s[3]);
			}
			ft_putchar(s[4]);
		}
		ft_putchar('\n');
		l = x - 2;
		y--;
	}
}

void	rush(int x, int y)
{
	char	s[5];

	s[0] = '/';
	s[1] = '*';
	s[2] = '\\';
	s[3] = ' ';
	s[4] = '*';
	if (y > 0 && x > 0)
	{
		ft_line(x, s, 0);
		ft_body(x, y, s);
		if (y > 1)
		{
			ft_line(x, s, 1);
		}
	}
}