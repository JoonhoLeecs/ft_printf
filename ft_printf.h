/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:00 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 18:53:17 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef long long int	t_ull;

int		ft_printf(const char *str, ...);
char	*ft_str_to_fields(char *str, va_list va_ptr, t_list **fields, int *ne);
char	*ft_chrs_to_field(char *str, t_list **fields);
char	*ft_terminate_on_error(char *str, t_list **fields);
char	*ft_convert_format(char *str, va_list va_ptr, t_list **fields, int *ne);

char	*ft_chr_to_str(char c, int *ne);
char	*ft_ptraddress_to_str(void *ptr);
char	*ft_ulltostr_base(t_ull nbr_decimal, char *base_to);
char	*ft_longtostr_base(long nbr_decimal, char *base_to);

int		ft_lstiter_strlensum(t_list *lst);
void	ft_free_fields(void *ptr);

#endif
