CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -arch x86_64

LIBFT	= -L./libft -lft

NAME	= libftprintf.a
SRCS	= ./srcs/ft_printf.c \
		  ./srcs/ft_printf_utils.c \
		  ./srcs/fmt_utils.c \
		  ./srcs/print_char_series.c \
		  ./srcs/print_decimal.c \
		  ./srcs/print_u_decimal.c \
		  ./srcs/print_hexa.c \
		  ./srcs/hexa_utils.c \
		  ./srcs/print_address.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft
		cp libft/libft.a ./$(NAME)
		ar -crs $(NAME) $(OBJS)
		
bonus: all

libft:
		@$(MAKE) -C ./libft all

clean:
		@$(MAKE) -C ./libft clean
		rm -rf $(OBJS)

fclean: clean
		@$(MAKE) -C ./libft fclean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all, clean, fclean, re, libft
