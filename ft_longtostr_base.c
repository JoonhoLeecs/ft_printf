/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtostr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:18:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 14:30:37 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static int	base_length_check(char *base);
static int	count_digit(long nbr_decimal, char *base_to);
static void	recur_longtostr(char *result, int *res_ind, long nbr, char *base);

char	*ft_longtostr_base(long nbr_decimal, char *base_to)
{
	char	*result;
	int		l_base;
	int		res_ind;

	result = (char *)malloc(count_digit(nbr_decimal, base_to) + 1);
	if (result == 0)
		return (0);
	res_ind = 0;
	while (res_ind < count_digit(nbr_decimal, base_to) + 1)
		result[res_ind++] = 0;
	res_ind = 0;
	recur_longtostr(result, &res_ind, nbr_decimal, base_to);
	result[res_ind] = '\0';
	return (result);
}

static int	base_length_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int	count_digit(long nbr_decimal, char *base_to)
{
	long	l_base;
	int		n_digits;

	l_base = (long)base_length_check(base_to);
	n_digits = 1;
	if (nbr_decimal < 0)
		n_digits += 1;
	while (nbr_decimal / l_base != 0)
	{
		nbr_decimal = nbr_decimal / l_base;
		n_digits += 1;
	}
	return (n_digits);
}

static void	recur_longtostr(char *result, int *res_ind, long nbr, char *base)
{
	long	l_base;

	l_base = (long)base_length_check(base);
	if (nbr < 0)
	{
		result[*res_ind] = '-';
		*res_ind += 1;
		if (nbr / l_base != 0)
			recur_longtostr(result, res_ind, (nbr / l_base) * -1, base);
		recur_longtostr(result, res_ind, (nbr % l_base) * -1, base);
	}
	if (nbr / l_base == 0)
	{
		result[*res_ind] = base[nbr % l_base];
		*res_ind += 1;
	}
	if (nbr / l_base > 0)
	{
		recur_longtostr(result, res_ind, nbr / l_base, base);
		recur_longtostr(result, res_ind, nbr % l_base, base);
	}
}