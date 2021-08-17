#include <unistd.h>
//rappel des variables en haut
void	ft_write(int tabl[4][4]);
void	ft_pos(int *str, int *sw1, int *sw2, int *swm);
void	ft_swap(int *a, int *b);
int		ft_verif_col(int tabl[4][4], char *str);
int		verifcol2(int *nbr, int i, char *str);
void	verifcol1(int *nbr, int *max, int *i, int tabl[4][4]);
int		ft_verif_colinv(int tabl[4][4], char *str);
int		verifcolinv2(int *nbr, int i, char *str);
void	verifcolinv1(int *nbr, int *max, int *i, int tabl[4][4]);
int		ft_verif(int tabl[4][4], char *str);
int		ft_verif_rowinv(int tabl[4][4], char *str);
int		verifrowinv2(int *nbr, int i, char *str);
void	verifrowinv1(int *nbr, int *max, int *j, int tabl[4]);
int		ft_verif_row(int tabl[4][4], char *str);
int		verifrow2(int *nbr, int i, char *str);
void	verifrow1(int *nbr, int *max, int *j, int tabl[4]);
int		verif_double(int t[4][4]);
//Le main


int	main(int arg, char **tab)
{
	// declaration des variables
	char	*str;
	int		a;
	int		b;
	int		c;
	int		d;
	int		sw1;
	int		sw2;
	int		swm;
	int		tabl[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	sw1 = 0;
	sw2 = 0;
	swm = 3;
	str = tab[1];
	// Error si il y a plus d'un argument
	if (arg != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	// Boucle qui change toutes les lignes et fait les tests (le brutforce quoi)
	while (d < 50)
	{
		while (c < 25)
		{
			while (b < 25)
			{
				while (a < 25)
				{
					// si la verif est juste on affiche la solution
					if (ft_verif(tabl, str) == 1)
					{
						ft_write(tabl);
						return (0);
					}
					// Swap la position des chiffre dans la ligne
					ft_pos(tabl[0], &sw1, &sw2, &swm);
					a++;
				}
				//pareil ect...
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
	// Ecris Error si toutes les solutions sont fausses
	write(1, "Error\n", 6);
}
// La fonction qui permet d'ecrire la solution juste
void	ft_write(int tabl[4][4])
{
	int		i;
	int		j;
	char	a;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			a = tabl[j][i] + '0';
			write(1, &a, 1);
			write(1, " ", 1);
			i++;
		}
		a = tabl[j][i] + '0';
		write(1, &a, 1);
		write(1, "\n", 1);
		j++;
	}
	return ;
}
// La fonction qui change la position des chiffres sur une lignes
void	ft_pos(int *str, int *sw1, int *sw2, int *swm)
{
	while (*swm > 0)
	{
		while (*sw2 < 2)
		{
			while (*sw1 < 1)
			{
				//Les 2 derniers
				ft_swap(&str[2], &str[3]);
				*sw1 = *sw1 + 1;
				return ;
			}
			// 2 eme et 3 eme
			*sw1 = 0;
			ft_swap(&str[1], &str[3]);
			*sw2 = *sw2 + 1;
			return ;
		}
		//le premier avec le 4 puis le 3 puis 2
		*sw2 = 0;
		ft_swap(&str[0], &str[*swm]);
		*swm = *swm - 1;
		return ;
	}
	*swm = 3;
	ft_pos(str, sw1, sw2, swm);
}
//Un ft_swap basic
void	ft_swap(int *a, int *b)
{
	char	c;
	c = *a;
	*a = *b;
	*b = c;
}
//fonction qui verifie les colonne en partant du haut
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
//Compare le nbr compter avec les chiffre donner par le tuteur
int	verifcol2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[0] - 48)
			return (0);
	if (i == 1)
		if (*nbr != str[2] - 48)
			return (0);
	if (i == 2)
		if (*nbr != str[4] - 48)
			return (0);
	if (i == 3)
		if (*nbr != str[6] - 48)
			return (0);
	return (1);
}
//compte le nombre de caisses visibles
void	verifcol1(int *nbr, int *max, int *i, int tabl[4][4])
{
	int	j;
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
//Meme fonction que en haut juste compare les colonne en partant du bas
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
		verifcolinv1 (&nbr, &max, &i, tabl);
		if (verifcolinv2 (&nbr, i, str) == 0)
			return (0);
		i++;
	}
	return (1);
}
//compare le nbr au arguments du tuteur
int	verifcolinv2(int nbr[4], int i, char *str)
{
	if (i == 0)
		if (*nbr != str[8] - 48)
			return (0);
	if (i == 1)
		if (*nbr != str[10] - 48)
			return (0);
	if (i == 2)
		if (*nbr != str[12] - 48)
			return (0);
	if (i == 3)
		if (*nbr != str[14] - 48)
			return (0);
	return (1);
}
//Compte le nombre de caisses visibles
void	verifcolinv1(int *nbr, int *max, int *i, int tabl[4][4])
{
	int	j;
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
// Regroupe toutes les fonctions de verifications
int	ft_verif(int tabl[4][4], char *str)
{
	if (verif_double(tabl) == 0)
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
// Verifie les lignes en partant de la droite (d'ou le inv)
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
//Compare les nbr au args
int	verifrowinv2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[24] - 48)
			return (0);
	if (i == 1)
		if (*nbr != str[26] - 48)
			return (0);
	if (i == 2)
		if (*nbr != str[28] - 48)
			return (0);
	if (i == 3)
		if (*nbr != str[30] - 48)
			return (0);
	return (1);
}
//Calcule les nbr
void	verifrowinv1(int *nbr, int *max, int *j, int tabl[4])
{
	if (tabl[*j] > *max)
	{
		*max = tabl[*j];
		*nbr = *nbr + 1;
	}
	*j = *j - 1;
}
//verification des lignes en partant de gauche
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
//Compare nbr au args
int	verifrow2(int *nbr, int i, char *str)
{
	if (i == 0)
		if (*nbr != str[16] - 48)
			return (0);
	if (i == 1)
		if (*nbr != str[18] - 48)
			return (0);
	if (i == 2)
		if (*nbr != str[20] - 48)
			return (0);
	if (i == 3)
		if (*nbr != str[22] - 48)
			return (0);
	return (1);
}
//calc nbr
void	verifrow1(int *nbr, int *max, int *j, int tabl[4])
{
	if (tabl[*j] > *max)
	{
		*max = tabl[*j];
		*nbr = *nbr + 1;
	}
	*j = *j + 1;
}
//Verifie qu'il n'y a pas de doublon dans les colonnes de notre tableau
int	verif_double(int t[4][4])
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