/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:36:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 14:59:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static char	*ft_format_tag_to_raw_str(const char *str, va_list va_ptr);

char	*ft_convert_format(const char *str, va_list va_ptr, t_list **fields)
{
	char	*new_content;
	t_list	*new_field;

	new_content = ft_format_tag_to_raw_str(str, va_ptr);
	if (new_content == 0)
		return (ft_terminate_on_error(str, fields));
	new_field = ft_lstnew(new_content);
	if (new_field == 0)
		return (ft_terminate_on_error(str, fields));
	ft_lstadd_back(fields, new_field);
	return (str + 2);
}

static char	*ft_format_tag_to_raw_str(const char *str, va_list va_ptr)
{
	char	*format_specifier_pool;
	char	*specifier;
	char	*raw_str;

	format_specifier_pool = "cspdiuxX%";
	specifier = ft_strchr(format_specifier_pool, *(str + 1));
	if (specifier == 0)
		return (0);
	else if (specifier - format_specifier_pool == 0)
		return (ft_chr_to_str(va_arg(va_ptr, char)));
	else if (specifier - format_specifier_pool == 1)
		return (ft_strdup(va_arg(va_ptr, char *)));
	else if (specifier - format_specifier_pool == 2)
		return (ft_ptraddress_to_str(va_arg(va_ptr, void *)));
	else if (specifier - format_specifier_pool == 3
		|| specifier - format_specifier_pool == 4)
		return (ft_itoa(va_arg(va_ptr, int)));
	else if (specifier - format_specifier_pool == 5)
		return (ft_ulltostr_base(va_arg(va_ptr, unsigned int), "0123456789"));
	else if (specifier - format_specifier_pool == 6)
		return (ft_longtosre_base(va_arg(va_ptr, int), "0123456789abcdef"));
	else if (specifier - format_specifier_pool == 7)
		return (ft_longtostr_base(va_arg(va_ptr, int), "0123456789ABCDEF"));
	else if (specifier - format_specifier_pool == 8)
		return (ft_chr_to_str('%'));
}
