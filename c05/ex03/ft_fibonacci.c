/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:30:49 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/16 14:30:50 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_fibonacci(int index)
{
	int res;

	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return res;
}

int main(void)
{
	while(1){
	int index;
	scanf("%d", &index);
	printf("%d\n", ft_fibonacci(index));
	}
}