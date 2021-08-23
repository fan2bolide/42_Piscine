/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <bjeannot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:47:19 by njennes           #+#    #+#             */
/*   Updated: 2021/08/17 17:54:15 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_init_queens(int queens[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
}

void	ft_show_board(int queens[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + queens[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_check(int queens[10], int depth, int *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < depth)
	{
		j = i + 1;
		while (j < 10)
		{
			if (queens[i] == queens[j])
				return ;
			if (j - i == queens[i] - queens[j] || -(j - i) == queens[i] - queens[j])
				return ;
			j++;
		}
		i++;
	}
	if (depth == 9)
	{
		*result = *result + 1;
		ft_show_board(queens);
	}
}

void	ft_move_queens(int queens[10], int depth, int *result)
{
	while (queens[depth] < 10)
	{
		if (depth < 9 && queens[depth + 1] < 9)
			ft_move_queens(queens, depth + 1, result);
		ft_check(queens, depth, result);
		queens[depth]++;
	}
	queens[depth] = 0;
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	result;

	result = 0;
	ft_init_queens(queens);
	ft_move_queens(queens, 0, &result);
	return (result);
}



int	main(void)
{
	printf("%d\n",ft_ten_queens_puzzle());
}