/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 18:45:07 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chr_to_str(char c, int *ne)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == 0)
		return (0);
	result[0] = c;
	result[1] = '\0';
	if (c == 0)
		*ne += 1;
	return (result);
}
