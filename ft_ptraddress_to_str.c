/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptraddress_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:06:06 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 13:52:12 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_ptraddress_to_str(void *ptr)
{
	unsigned long long	address;

	address = (unsigned long long) ptr;
	return (ft_ulltostr_base(address, "0123456789ABCDEF"));
}
