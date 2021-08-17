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
    int counter;

    i = 0;
    while (i <= 6)
    {
        counter = 0;
        while (counter <= 6)
        {
            if (ft_verif_line())
                break;
            ft_swap(tab[(counter + 1 % 2)+1][3]);
            counter++;
            if (ft_verif_line(tab[][]))
                break;
            ft_swap();
            counter++;
        }
        ft_swap(tab) //1ere et 3 - i
        ft_verif_line(tab[][], lines);

        //ft_verif
        // swap entre (counter + 1 % 2)+1 et 3
        //counter++ (counter = 1)
        //ft_verif
        // swap entre 1 et 3
        //counter++ (counter = 2)
        //ft_verif
        // swap entre 2 et 3
        //counter++ (counter = 3)
        //ft_verif
        // swap entre 1 et 3
        //counter++ (counter = 4)
        //ft_verif
        // swap entre 2 et 3
        //counter++ (counter = 5)
        //ft_verif
        // swap entre 1 et 3
        //counter++ (counter = 6)
        //counter == 6
            //
    }
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
int	ft_verif_lines(int *tab[][],int lines[])
{
	int i;
    int j;
    int max;
    int views;

    views = 0;
    i = 0;
    j = 0;
    while (i < 4)
    {
        max = 0;
        views = 0;
        while (j < 4))
        {
            if (tab[i][j] > max)
            {
                max = tab[i][j];
                views++;
            }
            j++;
        }
        if (views != lines[i])
            return (i);
        i++;
    }
    return (10);
}
//prends en parametres le tableau a 2 dimensions
//renvoie l'indice de la colonne fausse ou 10 si toutes les colones sont justes.
int ft_verif_cols(int *tab[][], int cols[])
{
	int i;
    int j;
    int max;
    int views;

    i = 0;
    j = 0;
    while (i < 4)
    {
        max = 0;
        views = 0;
        while (j < 4))
        {
            if (tab[j][i] > max)
            {
                max = tab[i][j];
                views++;
            }
            j++;
        }
        if (views != cols[i])
            return (i);
        i++;
    }
    return (10);
}