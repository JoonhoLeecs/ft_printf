/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:01:40 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 20:15:03 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_putfield(void *s);

int	ft_printf(const char *str, ...)
{
	va_list	va_ptr;
	t_list	*field_lst;
	int		num_char;

	if (str == 0)
		return (-1);
	va_start(va_ptr, str);
	field_lst = 0;
	if (*str == 0)
		ft_convert_empty_str(&field_lst, (char *)str);
	while (*str)
		str = ft_str_to_fieldlst((char *)str, va_ptr, &field_lst);
	num_char = ft_lstiter_strlensum(field_lst);
	if (num_char != -1)
		ft_lstiter(field_lst, &ft_putfield);
	ft_lstclear(&field_lst, &ft_clear_field);
	va_end(va_ptr);
	return (num_char);
}

static void	ft_putfield(void *content)
{
	t_field	*ptr;
	int		check;

	ptr = (t_field *)content;
	check = write(1, ptr->str, ptr->len);
}
