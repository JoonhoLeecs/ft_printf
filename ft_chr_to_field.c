/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/24 16:28:23 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_field	*ft_chr_to_field(char c)
{
	char	*raw_str;
	t_field	*new_field;

	raw_str = (char *)malloc(2 * sizeof(char));
	if (raw_str == 0)
		return (0);
	raw_str[0] = c;
	raw_str[1] = '\0';
	new_field = ft_newfield(raw_str, 1);
	if (new_field == 0)
		free (raw_str);
	return (new_field);
}
