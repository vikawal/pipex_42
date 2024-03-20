NAME = pipex
FLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
SRCS = \
free_utils.c \
path_and_mistake.c \
pipex_main.c


OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./LIBFT
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

# test: all
# 	./$(NAME)


.PHONY: all clean fclean re test