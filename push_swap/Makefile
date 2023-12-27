CFLAGC = -Wall -Wextra -Werror
CC = gcc
c_src = push_swap_utils.c push_swap_utils_list.c push_swap_utils_continued.c push_swap_algorithms.c push_swap_radix.c ft_split.c ft_actions.c ft_actions_pr.c ft_actions_rrr.c 
c_obj=$(c_src:.c=.o)
push_swap = push_swap 

all: $(push_swap)


$(push_swap):$(c_obj) push_swap.h
	$(CC) $(CFLAGS) push_swap_main.c $(c_obj) -o $(push_swap)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj)
fclean: clean
	rm -rf $(push_swap)
re: fclean all