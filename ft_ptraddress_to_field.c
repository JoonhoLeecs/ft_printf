/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptraddress_to_field.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:06 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 16:29:58 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_field	*ft_ptraddress_to_field(void *ptr)
{
	unsigned long long	address;
	char				*raw_address;
	char				*raw_str;
	t_field				*new_field;


	address = (unsigned long long) ptr;
	raw_address = ft_ulltostr_base(address, "0123456789abcdef");
	if (raw_address == 0)
		return (0);
	raw_str = ft_strjoin("0x", raw_address);
	free(raw_address);
	if (raw_str == 0)
		return (0);
	new_field = ft_newfield(raw_str, ft_strlen(raw_str));
	if (new_field == 0)
		free(raw_str);
	return (new_field);
}
