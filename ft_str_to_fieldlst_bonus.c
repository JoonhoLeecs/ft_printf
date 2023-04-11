/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_fieldlst_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:23:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*ft_str_to_fieldlst(char *str, va_list va_ptr, t_list **field_lst)
{
	char	*ptr_next_field;

	if (*str != '%')
		return (ft_chrs_to_field(str, field_lst));
	ptr_next_field = ft_convert_format(str, va_ptr, field_lst);
	return (ptr_next_field);
}
