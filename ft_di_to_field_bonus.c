/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_to_field_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:31:09 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 07:12:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf_bonus.h"

t_field	*ft_di_to_field(int d)
{
	char	*raw_str;
	t_field	*new_field;

	raw_str = ft_itoa(d);
	if (raw_str == 0)
		return (0);
	new_field = ft_newfield(raw_str, ft_strlen(raw_str));
	if (new_field == 0)
		free(raw_str);
	return (new_field);
}
