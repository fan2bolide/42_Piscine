/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdevigne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:55:22 by fdevigne          #+#    #+#             */
/*   Updated: 2021/08/07 14:55:27 by fdevigne         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_line(int i, char s[5], int token)
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
		token = 0;
		f = 2;
	}
	l = i - 2;
	ft_putchar(s[token]);
	while (l-- > 0)
	{
		ft_putchar(s[1]);
	}
	if (i > 1)
	{
		ft_putchar(s[f]);
	}
	ft_putchar('\n');
}

void	ft_body(int i, int x, char s[5])
{
	int	l;

	l = i - 2;
	x = x - 2;
	while (x > 0)
	{
		ft_putchar(s[4]);
		if (i > 1)
		{
			while (l-- > 0)
			{
				ft_putchar(s[3]);
			}
			ft_putchar(s[4]);
		}
		ft_putchar('\n');
		l = i - 2;
		x--;
	}
}

void	rush(int i, int x)
{
	char	s[5];

	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'C';
	s[3] = ' ';
	s[4] = 'B';
	if (x > 0 && i > 0)
	{
		ft_line(i, s, 0);
		ft_body(i, x, s);
		if (x > 1)
		{
			ft_line(i, s, 1);
		}
	}
}
