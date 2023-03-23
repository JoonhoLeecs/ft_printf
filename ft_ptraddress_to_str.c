/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptraddress_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:06 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 16:57:47 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_ptraddress_to_str(void *ptr)
{
	unsigned long long	address;
	char				*raw_str;
	char				*result;

	address = (unsigned long long) ptr;
	raw_str = ft_ulltostr_base(address, "0123456789abcdef");
	if (raw_str == 0)
		return (0);
	result = ft_strjoin("0x", raw_str);
	free(raw_str);
	return (result);
}
