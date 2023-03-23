CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR_LIBFT = ./libft/
LIBFT = libft.a
SRC = ft_chr_to_str.c \
		ft_chrs_to_field.c \
		ft_convert_format.c \
		ft_free_fields.c \
		ft_longtostr_base.c \
		ft_lstiter_strlensum.c \
		ft_printf.c \
		ft_printf.o \
		ft_ptraddress_to_str.c \
		ft_str_to_fields.c \
		ft_terminate_on_error.c \
		ft_ulltostr_base.c
OBJECTS = $(SRC:.c=.o)
NAME = libftprintf.a

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : make_all

make_all : $(LIBFT) $(OBJECTS)
			$(AR) rcs $(NAME) $(OBJECTS)
			@touch make_all
# @rm -f make_bonus

$(LIBFT) :
	$(MAKE) bonus -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) $(NAME)

# bonus : make_bonus

# make_bonus : $(OBJECTS) $(OBJECTS_BONUS)
# 			$(AR) rcs $(NAME) $^
# 			@touch make_bonus
# 			@rm -f make_all

clean :
	cd $(DIR_LIBFT); $(MAKE) clean
	rm -f $(OBJECTS)
	rm -f $(LIBFT)
	rm -f make_all

fclean :
	$(MAKE) clean
	cd $(DIR_LIBFT); $(MAKE) fclean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
