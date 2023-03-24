/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capx_to_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:48:19 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 16:49:32 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_field	*ft_capx_to_field(unsigned int capx)
{
	char	*raw_str;
	t_field	*new_field;

	raw_str = ft_ulltostr_base(capx, "0123456789ABCDEF");
	if (raw_str == 0)
		return (0);
	new_field = ft_newfield(raw_str, ft_strlen(raw_str));
	if (new_field == 0)
		free(raw_str);
	return (new_field);
}
