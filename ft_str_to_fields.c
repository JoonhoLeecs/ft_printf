/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_fields.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:23:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 11:03:14 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_str_to_fields(char *str, va_list va_ptr, t_list **fields)
{
	char	*ptr_next_field;
	char	*new_content;
	t_list	*new_field;

	if (*str != '%')
		return (ft_chrs_to_field(str, fields));
	if (ft_strlen(str) == 1)
		return (ft_terminate_on_error(str, fields));
	ptr_next_field = ft_convert_format_tags(str, va_ptr, fields);
	return (ptr_next_field);
}
