CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -arch x86_64

NAME    = libft.a
SRCS    = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_isspace.c ft_strcpy.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \
		ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS1   = $(SRCS:.c=.o)

OBJS2	= $(BONUS:.c=.o)


all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(SRCS) $(BONUS)
		ar rc $(NAME) $(OBJS1) $(OBJS2)

bonus:
		$(CC) $(CFLAGS) -c $(BONUS) -include libft.h
		ar rc $(NAME) $(OBJS2)

clean:
		rm -f $(OBJS1) $(OBJS2)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re, bonus
