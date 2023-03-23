CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR_LIBFT = ./libft/
NAME_LIBFT = libft.a
SRC = ft_printf.c ft_strjoin_free.c
OBJECTS = $(SRC:.c=.o)
NAME = libftprintf.a

.PHONY: all bonus clean fclean re

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : make_all

make_all : $(NAME_LIBFT) $(OBJECTS)
			cd $(SRCDIR_LIBFT)
			$(MAKE) bonus
			cp $(NAME_LIBFT) ../$(NAME)
			$(AR) rcs $(NAME) $^
			@touch make_all
			@rm -f make_bonus

bonus : make_bonus

make_bonus : $(OBJECTS) $(OBJECTS_BONUS)
			$(AR) rcs $(NAME) $^
			@touch make_bonus
			@rm -f make_all

clean :
	cd $(SRCDIR_LIBFT)
	$(MAKE) clean
	cd ..
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	rm -f make_all make_bonus

fclean : clean
	cd $(SRCDIR_LIBFT)
	$(MAKE) fclean
	cd ..
	rm -f $(NAME)

re : fclean all
