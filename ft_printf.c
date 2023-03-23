/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:01:40 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 15:01:43 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static void	ft_putstr(void *s);

int	ft_printf(const char *str, ...)
{
	va_list	va_ptr;
	t_list	*fields;
	int		num_char;

	if (str == 0)
		return (-1);
	va_start(va_ptr, str);
	fields = 0;
	while (*str)
		str = ft_str_to_fields(str, va_ptr, &fields);
	num_char = ft_lstiter_strlensum(fields);
	if (num_char != -1)
		ft_lstiter(fields, &ft_putstr);
	ft_lstclear(&fields, &ft_free_fields);
	va_end(va_ptr);
	return (num_char);
}

static void	ft_putstr(void *s)
{
	char	*ptr;

	ptr = (char *)s;
	ft_putstr_fd(ptr, 1);
}
