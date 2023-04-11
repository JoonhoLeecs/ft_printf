/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newfield_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:53:44 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

t_field	*ft_newfield(char *str, size_t len)
{
	t_field	*new_field;

	new_field = (t_field *) malloc(sizeof(t_field));
	if (new_field == 0)
		return (0);
	new_field->str = str;
	new_field->len = len;
	return (new_field);
}
