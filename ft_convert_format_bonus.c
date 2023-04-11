/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_format_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static t_field	*ft_argument_to_field(char *str, va_list va_ptr);

char	*ft_convert_format(char *str, va_list va_ptr, t_list **field_lst)
{
	t_field	*new_field;
	t_list	*new_node;
	char	*ptr_next;

	ptr_next = str + 2;
	if (*(str + 1) == 0)
	{
		new_field = ft_str_to_field("");
		ptr_next = str + 1;
	}
	else
		new_field = ft_argument_to_field(str + 1, va_ptr);
	if (new_field == 0)
		return (ft_terminate_on_error(str, field_lst));
	new_node = ft_lstnew(new_field);
	if (new_node == 0)
	{
		ft_clear_field(new_field);
		new_field = 0;
		return (ft_terminate_on_error(str, field_lst));
	}
	ft_lstadd_back(field_lst, new_node);
	return (ptr_next);
}

static t_field	*ft_argument_to_field(char *str, va_list va_ptr)
{
	char	*format_specifier_pool;
	char	*specifier;

	format_specifier_pool = "cspdiuxX%";
	specifier = ft_strchr(format_specifier_pool, *str);
	if (specifier == 0)
		return (ft_chr_to_field(*str));
	else if (specifier - format_specifier_pool == 0)
		return (ft_chr_to_field((char) va_arg(va_ptr, int)));
	else if (specifier - format_specifier_pool == 1)
		return (ft_str_to_field(va_arg(va_ptr, char *)));
	else if (specifier - format_specifier_pool == 2)
		return (ft_ptraddress_to_field(va_arg(va_ptr, void *)));
	else if (specifier - format_specifier_pool == 3
		|| specifier - format_specifier_pool == 4)
		return (ft_di_to_field(va_arg(va_ptr, int)));
	else if (specifier - format_specifier_pool == 5)
		return (ft_u_to_field(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 6)
		return (ft_x_to_field(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 7)
		return (ft_capx_to_field(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 8)
		return (ft_chr_to_field('%'));
	return (0);
}
