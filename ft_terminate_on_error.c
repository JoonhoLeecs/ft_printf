/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate_on_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:58:42 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 11:01:33 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_terminate_on_error(char *str, t_list **fields)
{
	if (*fields != 0)
	{
		free(ft_lstlast(*fields)->content);
		ft_lstlast(*fields)->content = 0;
	}
	return (str + ft_strlen(str));
}
