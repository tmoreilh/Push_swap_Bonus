NAME =	push_swap
CHECKER =	checker


SRCS = 						3n_sort.c\
							5n_sort.c\
							big_sort.c\
							main.c\
							setup.c\
							stack_ops.c\
							utils.c\
							moving.c\
							distance.c\
							target.c\
							check_errors.c
C_SRCS = 					bonus/get_next_line.c\
							bonus/get_next_line_utils.c\
							bonus/main.c\
							bonus/check_stack_ops.c\
							bonus/setup.c\
							bonus/target.c\
							bonus/utils.c\
							bonus/check_errors.c


OBJS =	$(SRCS:.c=.o)
C_OBJS =	$(C_SRCS:.c=.o)


CC =	gcc

CFLAG =	-g -Wall -Werror -Wextra

RM = 	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(CHECKER) : $(C_OBJS)
	$(CC) $(CFLAG) $^ -o $(CHECKER)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $^ -o $(NAME)


bonus : all $(CHECKER)

clean :
		$(RM) $(OBJS) $(C_OBJS)

fclean : clean
		$(RM) $(NAME) $(CHECKER)

re : fclean all

.PHONY :
		all clean fclean re