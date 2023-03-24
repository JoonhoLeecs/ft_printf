/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_empty_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:56:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 18:04:35 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_convert_empty_str(t_list **field_lst, char *str)
{
	char	*raw_str;
	t_list	*new_node;

	raw_str = ft_strdup(str);
	if (raw_str == 0)
		return ;
	new_node = ft_new_fieldnode_free(raw_str, 0);
	if (new_node == 0)
		return ;
	ft_lstadd_back(field_lst, new_node);
}
