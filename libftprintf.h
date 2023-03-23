/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:00 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/23 14:59:33 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef long long int	t_ull;

int		ft_printf(const char *str, ...);
char	*ft_str_to_fields(const char *str, va_list va_ptr, t_list **fields);
char	*ft_chrs_to_field(const char *str, t_list **fields);
char	*ft_terminate_on_error(const char *str, t_list **fields);
char	*ft_convert_format(const char *str, va_list va_ptr, t_list **fields);

char	*ft_chr_to_str(char c);
char	*ft_ptraddress_to_str(void *ptr);
char	*ft_ulltostr_base(t_ull nbr_decimal, char *base_to);
char	*ft_longtostr_base(long nbr_decimal, char *base_to);

int		ft_lstiter_strlensum(t_list *lst);
void	ft_free_fields(void *ptr);

#endif
