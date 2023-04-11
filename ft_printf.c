/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:28:06 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 10:41:07 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	va_ptr;
	int		check;
	int		count;
	int		len;

	va_start(va_ptr, str);
	check = 0;
	count = 0;
	i = 0;
	while (*(str + i) && check >= 0)
	{
		if (*(str + i) == '%')
			check = ft_print_format((str + i + 1), va_ptr, &i);
		else
		{
			len = find_next_tag_or_null((str + i));
			check = write(1, (str + i), len);
			i += len;
		}
		count = (check >= 0) * (count + check) + (check < 0) * (-1);
	}
	va_end(va_ptr);
	return (count);
}

int	find_next_tag_or_null(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
			break ;
		i++;
	}
	return (i);
}

int	ft_print_format(const char *str, va_list va_ptr, int *i)
{
	*i += 2;
	if (*str == 'c')
		return (ft_print_char((char) va_arg(va_ptr, int)));
	else if (*str == 's')
		return (ft_print_str(va_arg(va_ptr, char *)));
	else if (*str == 'p')
		return (ft_print_ptraddress(va_arg(va_ptr, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_nbr_di(va_arg(va_ptr, int)));
	else if (*str == 'u')
		return (ft_print_nbr_base(*str, va_arg(va_ptr, unsigned int)));
	else if (*str == 'x')
		return (ft_print_nbr_base(*str, va_arg(va_ptr, unsigned int)));
	else if (*str == 'X')
		return (ft_print_nbr_base(*str, va_arg(va_ptr, unsigned int)));
	else if (*str == '%')
		return (ft_print_char('%'));
	else
	{
		*i -= 1;
		return (0);
	}
}

int	ft_print_char(const char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str_arg)
{
	int	i;

	if (str_arg == 0)
		return (write(1, "(null)", 6));
	i = 0;
	while (*(str_arg + i))
		i++;
	return (write(1, str_arg, i));
}

int	ft_print_ptraddress(void *ptr)
{
	int					check;
	unsigned long long	ull_ptr;

	ull_ptr = (unsigned long long) ptr;
	check = write(1, "0x", 2);
	if (check < 0)
		return (-1);
	check = ft_print_nbr_base('x', ull_ptr);
	if (check < 0)
		return (-1);
	else
		return (check + 2);
}

int	ft_print_nbr_base(const char type, unsigned long long nbr)
{
	char				*base;
	unsigned long long	base_len;
	int					check;

	if (type == 'u' || type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	base_len = (type == 'u') * 10 + (type == 'x' || type == 'X') * 16;
	if (nbr / base_len == 0)
		return (write(1, (base + nbr % base_len), 1));
	else
	{
		check = ft_print_nbr_base(type, nbr / base_len);
		if (check < 0)
			return (check);
		if (ft_print_nbr_base(type, nbr % base_len) < 0)
			return (-1);
		else
			return (check + 1);
	}
}

int ft_print_nbr_di(long long nbr)
{
	char	*base;
	int		base_len;
	int		sign;
	int		check;

	base = "0123456789";
	base_len = 10;
	sign = (nbr < 0) * (-1) + (nbr >= 0) * 1;
	if (sign == -1)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		check = ft_print_nbr_di(nbr * sign);
		if (check < 0)
			return (check);
		else
			return (check + 1);
	}
	if (nbr / base_len == 0)
		return (write(1, (base + nbr % base_len), 1));
	else
	{
		check = ft_print_nbr_di(nbr / base_len);
		if (check < 0)
			return (check);
		if (ft_print_nbr_di(nbr % base_len) < 0)
			return (-1);
		else
			return (check + 1);
	}
}
