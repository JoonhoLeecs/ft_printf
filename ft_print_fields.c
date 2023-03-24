/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:21:57 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 20:32:24 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_print_fields(t_list *field_lst)
{
	t_field	*ptr;
	int		check;

	check = 0;
	if (field_lst == 0)
		return (-1);
	while (field_lst && check >= 0)
	{
		ptr = (t_field *)(field_lst->content);
		check = write(1, ptr->str, ptr->len);
		field_lst = field_lst->next;
	}
	return (check);
}
