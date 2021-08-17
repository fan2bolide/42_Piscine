#include <unistd.h>
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
	int	tabl[4][4];
	tabl[][] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	str = tab[1];
	if (arg != 2)
	{
		write (1, "Error\n", 1);
		return (0);
	}
	while (d != 25)
	{
		while (c != 25)
		{
			while (b != 25)
			{
				while (a != 25)
				{
					ft_pos(tabl[0], sw1, sw2, swm);
					if (ft_verif(tabl, str) == 1)
					{
						ft_write(tabl);
						return (0);
					}
					a++;
				}
				a = 0;
				b++;
			}
			b = 0;
			c++;
		}
		c = 0
		d++;
	}
}
void	ft_write(char **tabl)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (j != 4)
	{
		while (i != 3)
		{
			write (1, tabl[j][i], 1);
			write (1, " ", 1);
			i++;
		}
		write (1, tabl[j][i], 1);
	}
	j++;
}
int	ft_pos(char *str, int *sw1, int *sw2, int *swm)
{
	while (swm != -1)
	{
		while (sw2 != 2)
		{
			while(sw1 != 1)
			{
				ft_swap(str[2], str[3]);
				sw1++;
				return (0);
			}
			sw1 = 0;
			ft_swap(str[1], str[3]);
			sw2++;
			return (0);
		}
		sw2 = 0;
		ft_swap(str[0], str[swm]);
		swm--;
		return (0);
	}
	swm = 3;
	ft_pos(str, sw1, sw2, swm);
}
void	ft_swap(char *a, char *b)
{
	char	c;
	c = *a;
	*a = *b;
	*b = c;
}
int	ft_verif_col(char **tabl, char *str)
{
	int	i;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		verifcol1(nbr, max, i, tabl);
		if (verifcol2(nbr, j, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifcol2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (nbr != str[0])
			return (0);
	if (i == 1)
		if (nbr != str[2])
			return (0);
	if (i == 2)
		if (nbr != str[4])
			return (0);
	if (i == 3)
		if (nbr != str[6])
			return (0);
	return (1);
}
int	verifcol1(int *nbr, int *max, int *i, char **tabl)
{
	int j;
	j = 0;
	while (j < 4)
	{
		if (tabl[j][i] > max)
		{
			max = tabl[j][i];
			nbr++;
		}
		j++;
	}
}
int	ft_verif_colinv(char **tabl, char *str)
{
	int	i;
	int	max;
	int	nbr;
	i = 0;
	while (i < 4)
	{
		max = 0;
		nbr = 0;
		verifcolinv1(nbr, max, i, tabl);
		if (verifcolinv2(nbr, j, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifcolinv2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (nbr != str[8])
			return (0);
	if (i == 1)
		if (nbr != str[10])
			return (0);
	if (i == 2)
		if (nbr != str[12])
			return (0);
	if (i == 3)
		if (nbr != str[14])
			return (0);
	return (1);
}
int	verifcolinv1(int *nbr, int *max, int *i, char **tabl)
{
	int j;
	j = 3;
	while (j > -1)
	{
		if (tabl[j][i] > max)
		{
			max = tabl[j][i];
			nbr++;
		}
		j--;
	}
}
int	ft_verif(char **tabl, char *str)
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
int	ft_verif_rowinv(char **tabl, char *str)
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
			verifrowinv1(nbr, max, j, tabl[i];
		if (verifrowinv2(nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifrowinv2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (nbr != str[24])
			return (0);
	if (i == 1)
		if (nbr != str[26])
			return (0);
	if (i == 2)
		if (nbr != str[28])
			return (0);
	if (i == 3)
		if (nbr != str[30])
			return (0);
	return (1);
}
int	verifrowinv1(int *nbr, int *max, int *j, char *tabl)
{
	if (tabl[j] > max)
	{
		max = tabl[j];
		nbr++;
	}
	j--;
}
int	ft_verif_row(char **tabl, char *str)
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
			verifrow1(nbr, max, j, tabl[i];
		if (verifrow2(nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
int	verifrow2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (nbr != str[16])
			return (0);
	if (i == 1)
		if (nbr != str[18])
			return (0);
	if (i == 2)
		if (nbr != str[20])
			return (0);
	if (i == 3)
		if (nbr != str[22])
			return (0);
	return (1);
}
int	verifrow1(int *nbr, int *max, int *j, char *tabl)
{
	if (tabl[j] > max)
	{
		max = tabl[j];
		nbr++;
	}
	j++;
}
//verif des repetitions
int	verif_col(char **t)
{
	if (t[0][0] == t[1][0] || t[0][0] = t[2][0] || t[0][0] == t[3][0]
			|| t[1][0] == t[2][0] || t[1][0] == t[3][0] || t[2][0] == t[3][0])
		return (0);
	if (t[0][1] == t[1][1] || t[0][1] = t[2][1] || t[0][1] == t[3][1]
			|| t[1][1] == t[2][1] || t[1][1] == t[3][1] || t[2][1] == t[3][1])
		return (0);
	if (t[0][2] == t[1][2] || t[0][2] = t[2][2] || t[0][2] == t[3][2]
			|| t[1][2] == t[2][2] || t[1][2] == t[3][2] || t[2][2] == t[3][2])
		return (0);
	if (t[0][3] == t[1][3] || t[0][3] = t[2][3] || t[0][3] == t[3][3]
			|| t[1][3] == t[2][3] || t[1][3] == t[3][3] || t[2][3] == t[3][3])
		return (0);
	return (1);
}