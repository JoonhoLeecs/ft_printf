/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate_on_error_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:58:42 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*ft_terminate_on_error(char *str, t_list **field_lst)
{
	t_list	*last_node;

	if (*field_lst != 0)
	{
		last_node = ft_lstlast(*field_lst);
		ft_clear_field(last_node->content);
		last_node->content = 0;
	}
	return (str + ft_strlen(str));
}
