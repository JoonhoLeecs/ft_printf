/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 13:05:05 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_chr_to_str(char c)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == 0)
		return (0);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
