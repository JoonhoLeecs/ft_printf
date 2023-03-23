/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 18:52:00 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*ft_format_tag_to_raw_str(char *str, va_list va_ptr, int *ne);
static char	*ft_u_tag_to_str(unsigned int n);
static char	*ft_x_tag_to_str(unsigned int n);
static char	*ft_capx_tag_to_str(unsigned int n);

char	*ft_convert_format(char *str, va_list va_ptr, t_list **fields, int *ne)
{
	char	*new_content;
	t_list	*new_field;

	new_content = ft_format_tag_to_raw_str(str, va_ptr, ne);
	if (new_content == 0)
		return (ft_terminate_on_error(str, fields));
	new_field = ft_lstnew(new_content);
	if (new_field == 0)
		return (ft_terminate_on_error(str, fields));
	ft_lstadd_back(fields, new_field);
	return ((char *)(str + 2));
}

static char	*ft_format_tag_to_raw_str(char *str, va_list va_ptr, int *ne)
{
	char	*format_specifier_pool;
	char	*specifier;

	format_specifier_pool = "cspdiuxX%";
	specifier = ft_strchr(format_specifier_pool, *(str + 1));
	if (specifier == 0)
		return (0);
	else if (specifier - format_specifier_pool == 0)
		return (ft_chr_to_str((char) va_arg(va_ptr, int), ne));
	else if (specifier - format_specifier_pool == 1)
		return (ft_strdup(va_arg(va_ptr, char *)));
	else if (specifier - format_specifier_pool == 2)
		return (ft_ptraddress_to_str(va_arg(va_ptr, void *)));
	else if (specifier - format_specifier_pool == 3
		|| specifier - format_specifier_pool == 4)
		return (ft_itoa(va_arg(va_ptr, int)));
	else if (specifier - format_specifier_pool == 5)
		return (ft_u_tag_to_str(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 6)
		return (ft_x_tag_to_str(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 7)
		return (ft_capx_tag_to_str(va_arg(va_ptr, unsigned int)));
	else if (specifier - format_specifier_pool == 8)
		return (ft_chr_to_str('%', ne));
	return (0);
}

static char	*ft_u_tag_to_str(unsigned int n)
{
	return (ft_ulltostr_base(n, "0123456789"));
}

static char	*ft_x_tag_to_str(unsigned int n)
{
	return (ft_ulltostr_base(n, "0123456789abcdef"));
}

static char	*ft_capx_tag_to_str(unsigned int n)
{
	return (ft_ulltostr_base(n, "0123456789ABCDEF"));
}
