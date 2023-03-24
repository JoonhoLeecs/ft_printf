/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_strlensum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:09:40 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 16:55:55 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_lstiter_strlensum(t_list *lst)
{
	int		sum;
	t_field	*field_content;

	sum = 0;
	if (lst == 0)
		return (-1);
	while (lst)
	{
		field_content = lst->content;
		if (field_content == 0)
			return (-1);
		sum += field_content->len;
		lst = lst->next;
	}
	return (sum);
}
