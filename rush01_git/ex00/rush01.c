/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:35:15 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/14 14:35:16 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_tab(int nbr[]);

int	main(int argc, char *argv[])
{
	int	cols[4];
	int	lines[4];
	int	increment_arg;
	int	increment_cols;
	int	increment_lines

	if (argc > 0)
	{
		increment_arg = 0;
		while (increment_arg <= 6)
		{
			cols[increment_cols] = *argv[increment_arg];
			increment_cols++;	
			increment_arg += 2;
		}
		while (increment_arg <= 14)
		{
			lines[increment_lines] = *argv[increment_arg];
			increment_lines++;
			increment_arg += 2;
		}
		ft_tab(cols, lines);

	}
}

void	ft_tab(int nbr[])
{
	int sum;
	int tab[4][4];
	int i;
	int j;


}




/*
si nbr[i] > max
	max = nbr[i]
	ce qu'on voit++;
*/
void	ft_swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
void ft_tab_init(int *tab[][])
{
	int i;
	int j;

	i = 0;
	
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*tab[i][j] = ((i + j) % 4) + 1;
		}
	}
}
void	ft_print_tab(int *tab[][])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, tab[i][j], 1);
			write(1, ' ', 1);
		}
	}
}
void	ft_verif(int *tab[][], int cols[], int lines[])
{
	
}
