/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:22:58 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 13:15:29 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clear_field(void *ptr)
{
	t_field	*field_ptr;

	field_ptr = (t_field *)ptr;
	if (ptr == 0)
		return ;
	else
	{
		free(field_ptr->str);
		field_ptr->len = 0;
		free (field_ptr);
	}
}
