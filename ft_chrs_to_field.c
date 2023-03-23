/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrs_to_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:14:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 18:38:16 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*ft_find_start_of_next(char *str);

char	*ft_chrs_to_field(char *str, t_list **fields)
{
	char	*ptr_next_field;
	char	*new_content;
	t_list	*new_field;

	ptr_next_field = ft_find_start_of_next(str);
	new_content = ft_substr(str, 0, (size_t)(ptr_next_field - str));
	if (new_content == 0)
		return (ft_terminate_on_error(str, fields));
	new_field = ft_lstnew(new_content);
	if (new_field == 0)
		return (ft_terminate_on_error(str, fields));
	ft_lstadd_back(fields, new_field);
	return (ptr_next_field);
}

static char	*ft_find_start_of_next(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '%');
	if (ptr == 0)
		return (ft_strchr(str, 0));
	else
		return (ptr);
}
