/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltostr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:22:14 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 19:52:40 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	base_length_check(char *base);
static int	count_digit(t_ull nbr_decimal, char *base_to);
static void	recur_ulltostr(char *result, int *res_ind, t_ull nbr, char *base);

char	*ft_ulltostr_base(t_ull nbr_decimal, char *base_to)
{
	char	*result;
	int		res_ind;
	int		n_digits;

	n_digits = count_digit(nbr_decimal, base_to);
	result = (char *)malloc((n_digits + 1) * sizeof(char));
	if (result == 0)
		return (0);
	res_ind = 0;
	while (res_ind < n_digits + 1)
		result[res_ind++] = 0;
	res_ind = 0;
	recur_ulltostr(result, &res_ind, nbr_decimal, base_to);
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

static int	count_digit(t_ull nbr_decimal, char *base_to)
{
	t_ull	l_base;
	int		n_digits;

	l_base = (t_ull)base_length_check(base_to);
	n_digits = 1;
	while (nbr_decimal / l_base != 0)
	{
		nbr_decimal = nbr_decimal / l_base;
		n_digits += 1;
	}
	return (n_digits);
}

static void	recur_ulltostr(char *result, int *res_ind, t_ull nbr, char *base)
{
	t_ull	l_base;

	l_base = (t_ull)base_length_check(base);
	if (nbr / l_base == 0)
	{
		result[*res_ind] = base[nbr % l_base];
		*res_ind += 1;
	}
	if (nbr / l_base != 0)
	{
		recur_ulltostr(result, res_ind, nbr / l_base, base);
		recur_ulltostr(result, res_ind, nbr % l_base, base);
	}
}
