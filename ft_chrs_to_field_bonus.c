/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrs_to_field_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:14:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

static char	*ft_find_start_of_next(char *str);

char	*ft_chrs_to_field(char *str, t_list **field_lst)
{
	char	*ptr_next_field;
	size_t	len;
	char	*raw_string;
	t_list	*new_node;

	ptr_next_field = ft_find_start_of_next(str);
	len = (size_t)(ptr_next_field - str);
	raw_string = ft_substr(str, 0, len);
	if (raw_string == 0)
		return (ft_terminate_on_error(str, field_lst));
	new_node = ft_new_fieldnode_free(raw_string, len);
	if (new_node == 0)
		return (ft_terminate_on_error(str, field_lst));
	ft_lstadd_back(field_lst, new_node);
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
