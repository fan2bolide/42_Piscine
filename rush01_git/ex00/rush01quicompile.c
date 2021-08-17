#include <unistd.h>
void	ft_write(int tabl[4][4]);
void	ft_pos(int *str, int *sw1, int *sw2, int *swm);
void	ft_swap(int *a, int *b);
int	ft_verif_col(int tabl[4][4], char *str);
int	verifcol2(int *nbr, int i, char *str);
void	verifcol1(int *nbr, int *max, int *i, int tabl[4][4]);
int	ft_verif_colinv(int tabl[4][4], char *str);
int	verifcolinv2(int *nbr, int i, char *str);
void	verifcolinv1(int *nbr, int *max, int *i, int tabl[4][4]);
int	ft_verif(int tabl[4][4], char *str);
int	ft_verif_rowinv(int tabl[4][4], char *str);
int	verifrowinv2(int *nbr, int i, char *str);
void	verifrowinv1(int *nbr, int *max, int *j, int tabl[4]);
int	ft_verif_row(int tabl[4][4], char *str);
int	verifrow2(int *nbr, int i, char *str);
void	verifrow1(int *nbr, int *max, int *j, int tabl[4]);
int	verif_col(int t[4][4]);
int	main(int arg, char **tab)
{
	char	*str;
	int		a = 0;
	int		b = 0;
	int		c = 0;
	int		d = 0;
	int		sw1 = 0;
	int		sw2 = 0;
	int		swm = 3;
	int		tabl[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};

	//ft_write(tabl);
	str = tab[1];
	if (arg != 2)
	{
		write (1, "Error, <invalid args number>\n", 7);
		return (0);
	}
	while (d < 25)
	{
		while (c < 25)
		{
			while (b < 25)
			{
				while (a < 25)
				{
					ft_pos(tabl[0], &sw1, &sw2, &swm);
					write(1, "===\n", 4);
					ft_write(tabl);
					if (ft_verif(tabl, str) == 1)
					{
						ft_write(tabl);
						return (0);
					}
					a++;
				}
				ft_pos(tabl[1], &sw1, &sw2, &swm);
				a = 0;
				b++;
			}
			ft_pos(tabl[2], &sw1, &sw2, &swm);
			b = 0;
			c++;
		}
		ft_pos(tabl[3], &sw1, &sw2, &swm);
		c = 0;
		d++;
	}
	write(1, "Error\n", 6);
}
void	ft_write(int tabl[4][4])
{
	int	i;
	int	j;
	char a;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			a = tabl[j][i] + '0';
			write (1, &a, 1);
			write (1, " ", 1);
			i++;
		}
		a = tabl[j][i] + '0';
		write (1, &a, 1);
		write(1, "\n", 1);
	j++;
	}
	return;
}
void	ft_pos(int *str, int *sw1, int *sw2, int *swm)
{
	while (*swm > 0)
	{
		while (*sw2 < 2)
		{
			while(*sw1 < 1)
			{
				ft_swap(&str[2], &str[3]);
				*sw1 = *sw1 + 1;
				return;
			}
			*sw1 = 0;
			ft_swap(&str[1], &str[3]);
			*sw2 = *sw2 + 1;
			return;
		}
		*sw2 = 0;
		ft_swap(&str[0], &str[*swm]);
		*swm = *swm - 1;
		return;
	}
	*swm = 3;
	ft_pos(str, sw1, sw2, swm);
}
void	ft_swap(int *a, int *b)
{
	char	c;
	c = *a;
	*a = *b;
	*b = c;
}
int	ft_verif_col(int tabl[4][4], char *str)
{
	int	i;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		verifcol1(&nbr, &max, &i, tabl);
		if (verifcol2(&nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifcol2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[0])
			return (0);
	if (i == 1)
		if (*nbr != str[2])
			return (0);
	if (i == 2)
		if (*nbr != str[4])
			return (0);
	if (i == 3)
		if (*nbr != str[6])
			return (0);
	return (1);
}
void	verifcol1(int *nbr, int *max, int *i, int tabl[4][4])
{
	int j;
	j = 0;
	while (j < 4)
	{
		if (tabl[j][*i] > *max)
		{
			*max = tabl[j][*i];
			*nbr = *nbr + 1;
		}
		j++;
	}
}
int	ft_verif_colinv(int tabl[4][4], char *str)
{
	int	i;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		verifcolinv1(&nbr, &max, &i, tabl);
		if (verifcolinv2(&nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifcolinv2(int nbr[4], int i, char *str)
{
	if (i == 0)
		if (*nbr != str[8])
			return (0);
	if (i == 1)
		if (*nbr != str[10])
			return (0);
	if (i == 2)
		if (*nbr != str[12])
			return (0);
	if (i == 3)
		if (*nbr != str[14])
			return (0);
	return (1);
}
void	verifcolinv1(int *nbr, int *max, int *i, int tabl[4][4])
{
	int j;
	j = 3;
	while (j > -1)
	{
		if (tabl[j][*i] > *max)
		{
			*max = tabl[j][*i];
			*nbr = *nbr + 1;
		}
		j--;
	}
}
int	ft_verif(int tabl[4][4], char *str)
{
	if (verif_col(tabl) == 0)
		return (0);
	if (ft_verif_row(tabl, str) == 0)
		return (0);
	if (ft_verif_rowinv(tabl, str) == 0)
		return (0);
	if (ft_verif_col(tabl, str) == 0)
		return (0);
	if (ft_verif_colinv(tabl, str) == 0)
		return (0);
	return (1);
}
int	ft_verif_rowinv(int tabl[4][4], char *str)
{
	int	i;
	int	j;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		j = 3;
		while (j > -1)
		{
			verifrowinv1(&nbr, &max, &j, tabl[i]);
		}
		if (verifrowinv2(&nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifrowinv2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[24])
			return (0);
	if (i == 1)
		if (*nbr != str[26])
			return (0);
	if (i == 2)
		if (*nbr != str[28])
			return (0);
	if (i == 3)
		if (*nbr != str[30])
			return (0);
	return (1);
}
void	verifrowinv1(int *nbr, int *max, int *j, int tabl[4])
{
	if (tabl[*j] > *max)
	{
		*max = tabl[*j];
		*nbr = *nbr + 1;
	}
	*j = *j - 1;
}
int	ft_verif_row(int tabl[4][4], char *str)
{
	int	i;
	int	j;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		j = 0;
		while (j < 4)
		{
			verifrow1(&nbr, &max, &j, tabl[i]);
		}
			
		if (verifrow2(&nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifrow2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[16])
			return (0);
	if (i == 1)
		if (*nbr != str[18])
			return (0);
	if (i == 2)
		if (*nbr != str[20])
			return (0);
	if (i == 3)
		if (*nbr != str[22])
			return (0);
	return (1);
}
void	verifrow1(int *nbr, int *max, int *j, int tabl[4])
{
	if (tabl[*j] > *max)
	{
		*max = tabl[*j];
		*nbr = *nbr + 1;
	}
	*j = *j + 1;
}
//verif des repetitions
int	verif_col(int t[4][4])
{
	if (t[0][0] == t[1][0] || t[0][0] == t[2][0] || t[0][0] == t[3][0]
			|| t[1][0] == t[2][0] || t[1][0] == t[3][0] || t[2][0] == t[3][0])
		return (0);
	if (t[0][1] == t[1][1] || t[0][1] == t[2][1] || t[0][1] == t[3][1]
			|| t[1][1] == t[2][1] || t[1][1] == t[3][1] || t[2][1] == t[3][1])
		return (0);
	if (t[0][2] == t[1][2] || t[0][2] == t[2][2] || t[0][2] == t[3][2]
			|| t[1][2] == t[2][2] || t[1][2] == t[3][2] || t[2][2] == t[3][2])
		return (0);
	if (t[0][3] == t[1][3] || t[0][3] == t[2][3] || t[0][3] == t[3][3]
			|| t[1][3] == t[2][3] || t[1][3] == t[3][3] || t[2][3] == t[3][3])
		return (0);
	return (1);
}