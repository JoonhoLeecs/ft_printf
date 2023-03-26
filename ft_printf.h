/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:00 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/26 11:01:51 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_field
{
	char	*str;
	size_t	len;
}			t_field;

typedef unsigned long long	t_ull;

int		ft_printf(const char *str, ...);
void	ft_convert_empty_str(t_list **field_lst, char *str);
char	*ft_str_to_fieldlst(char *str, va_list va_ptr, t_list **field_lst);
char	*ft_chrs_to_field(char *str, t_list **field_lst);
t_field	*ft_newfield(char *str, size_t len);
t_list	*ft_new_fieldnode_free(char *raw_str, size_t len);
void	ft_clear_field(void *ptr);
char	*ft_terminate_on_error(char *str, t_list **field_lst);
char	*ft_convert_format(char *str, va_list va_ptr, t_list **field_lst);
t_field	*ft_chr_to_field(char c);
t_field	*ft_str_to_field(char *str);
t_field	*ft_ptraddress_to_field(void *ptr);
t_field	*ft_di_to_field(int d);
t_field	*ft_u_to_field(unsigned int u);
t_field	*ft_x_to_field(unsigned int x);
t_field	*ft_capx_to_field(unsigned int capx);
char	*ft_ulltostr_base(t_ull nbr_decimal, char *base_to);
int		ft_lstiter_strlensum(t_list *lst);
int		ft_print_fields(t_list *field_lst);

#endif
