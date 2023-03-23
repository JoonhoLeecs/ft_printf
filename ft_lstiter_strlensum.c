/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_strlensum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:09:40 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 18:30:36 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_lstiter_strlensum(t_list *lst)
{
	int	sum;

	sum = 0;
	if (lst == 0)
		return (-1);
	while (lst)
	{
		if (lst->content == 0)
			return (-1);
		sum += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (sum);
}
