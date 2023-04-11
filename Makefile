CC = cc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC =	ft_printf.c
OBJECTS = $(SRC:.c=.o)
SRC_BONUS =	ft_capx_to_field_bonus.c \
		ft_chr_to_field_bonus.c \
		ft_chrs_to_field_bonus.c \
		ft_clear_field_bonus.c \
		ft_convert_empty_str_bonus.c \
		ft_convert_format_bonus.c \
		ft_di_to_field_bonus.c \
		ft_lstiter_strlensum_bonus.c \
		ft_new_fieldnode_free_bonus.c \
		ft_newfield_bonus.c \
		ft_print_fields_bonus.c \
		ft_printf_bonus.c \
		ft_ptraddress_to_field_bonus.c \
		ft_str_to_field_bonus.c \
		ft_str_to_fieldlst_bonus.c \
		ft_terminate_on_error_bonus.c \
		ft_u_to_field_bonus.c \
		ft_ulltostr_base_bonus.c \
		ft_x_to_field_bonus.c

OBJECTS_BONUS = $(SRC_BONUS:.c=.o)
NAME = libftprintf.a

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : make_all

make_all : $(LIBFT) $(OBJECTS)
			$(AR) rcs $(NAME) $(OBJECTS)
			@touch make_all

# bonus : make_bonus

# make_bonus : $(LIBFT) $(OBJECTS_BONUS)
# 			$(AR) rcs $(NAME) $(OBJECTS_BONUS)
# 			@touch make_bonus

$(LIBFT) :
	$(MAKE) bonus -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(NAME)

clean :
	$(MAKE) clean -C $(DIR_LIBFT)
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	rm -f $(LIBFT)
	rm -f make_all make_bonus

fclean :
	$(MAKE) clean
	cd $(DIR_LIBFT); $(MAKE) fclean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
