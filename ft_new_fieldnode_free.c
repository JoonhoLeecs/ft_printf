/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fieldnode_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:46:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 11:56:14 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_list	*ft_new_fieldnode_free(char *raw_str, size_t len)
{
	t_field	*new_field;
	t_list	*new_node;

	new_field = ft_newfield(raw_str, len);
	if (new_field == 0)
	{
		free(raw_str);
		return (0);
	}
	new_node = ft_lstnew(new_field);
	if (new_node == 0)
	{
		free(raw_str);
		free(new_field);
		return (0);
	}
	return (new_node);
}
