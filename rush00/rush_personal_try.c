/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:36:04 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/07 12:36:10 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	rush(int x, int y);
void	ft_print_line(char **str, int x);
void	ft_print_rectangle(int x, int y, char **str_start, char **str_body, char **str_end);

int	main()
{
	rush(5, 5);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x, int y)
{
	int i;
	char *str_start[x];
	char *str_body[x];
	char *str_end[x];

	char bslash = '\\';
	char slash = '/';
	char star = '*';
	char space = ' ';

	i = 1;
	//j = 0;
	str_start[0] = &slash;
	str_start[x - 1] = &bslash;
	str_body[0] = &star;
	str_body[x - 1] = &star;
	//write(1, &str_body[x - 1], 1);
	str_end[0] = &bslash;
	str_end[x - 1] = &slash;
	while (i < x - 1)
	{
		str_start[i] = &star;
		str_end[i] = &star;
		str_body[i] = &space;
		i++;
	}
	ft_print_rectangle( x,  y, str_start,  str_body,  str_end);
}

void	ft_print_rectangle(int x, int y, char **str_start, char **str_body, char **str_end)
{
	int i;
	
	i = 1;
	ft_print_line(str_start, x);

	while (i < y - 1)
	{
		ft_print_line(str_body, x);
		i++;
	}
	ft_print_line(str_end, x);
}

void	ft_print_line(char **str, int x)
{
	int i;
	i = 0;
	while (i < x)
	{
		write(1, str[i], 1);
		//ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}
