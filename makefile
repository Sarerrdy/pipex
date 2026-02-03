NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = mandatory/main.c \
       mandatory/pipex.c \
       mandatory/fd_utils.c \
       mandatory/path_utils.c \
       mandatory/error.c \
       mandatory/clean_up.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all