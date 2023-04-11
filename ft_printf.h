/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 07:29:47 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 10:35:55 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	find_next_tag_or_null(const char *str);
int	ft_print_char(char c);
int	ft_print_format(const char *str, va_list va_ptr, int *i);
int	ft_print_str(char *str_arg);
int	ft_print_ptraddress(void *ptr);
int	ft_print_nbr_base(const char type, unsigned long long nbr);
int	ft_print_nbr_di(long long nbr);

#endif
