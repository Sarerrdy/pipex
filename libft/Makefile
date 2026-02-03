NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs
RM      := rm -f

SRC_CHAR := \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c

SRC_STRING := \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
	ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c

SRC_MEMORY := \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_calloc.c

SRC_CONVERT := \
	ft_atoi.c ft_itoa.c

SRC_ITER := \
	ft_strmapi.c ft_striteri.c

SRC_FD := \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

SRCS := $(SRC_CHAR) $(SRC_STRING) $(SRC_MEMORY) $(SRC_CONVERT) $(SRC_ITER) $(SRC_FD)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all