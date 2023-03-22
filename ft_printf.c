/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:01:40 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/20 18:52:44 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		num_char;
	va_list	va_ptr;
	int		num_param;
	char	*result;
	char	*temp;
	char	*temp2;

	num_char = 0;
	va_start(va_ptr, num_param);
	result = ft_strdup("");
	if(!result)
		result (-1);
	while (*str)
	{
		temp = ft_strchr(str, '%');
		if(!temp)
		{
			result = ft_strjoin_free(result, str);
			if (!result)
				return (-1);
			break ;
		}
		temp2 = ft_substr(str, 0, temp - str);
		result = ft_strjoin(result, temp2);
		free(temp2);
		if (!result)
			return (-1);
		ft_checkformat(temp);
		str = str + next_ind();

	}
	ft_putstr_fd(result, 1);
	num_char = ft_strlen(result);
	free(result);
	return (num_char);
}
