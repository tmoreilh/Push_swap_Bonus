CHECKER =	checker

C_SRCS = 					get_next_line.c\
							get_next_line_utils.c\
							main.c\
							checker_stack_ops.c\
							setup.c\
							target.c\
							utils.c\
							check_errors.c

C_OBJS =	$(C_SRCS:.c=.o)

CC =	gcc

CFLAG =	-g -Wall -Werror -Wextra -fsanitize=address

RM = 	rm -f

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(CHECKER) : $(C_OBJS)
	$(CC) $(CFLAG) $^ -o $(CHECKER)

all : $(CHECKER)

clean :
		$(RM) $(C_OBJS)

fclean : clean
		$(RM) $(CHECKER)

re : fclean all

.PHONY :
		all clean fclean re