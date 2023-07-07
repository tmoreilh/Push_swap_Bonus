/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:14:23 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:14:25 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				pos;
	int				target;
	int				dist;
	int				up;
	struct s_list	*next;
}	t_list;

int			get_next_line(int fd, char **line);
char		*mv_next_line(char **line_dest, char *str);
int			n_search(char *str);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(char const *str);
char		*first_line(char *str);
char		*cut_first_line(char *str);
int			mv_first_line(char *str, char **dest);
char		*sup_first_line(char *str);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		do_the_move(char *str, t_list **stack, \
			t_list **stackA, t_list **stackB);

// checker
void		c_swap(t_list **stack);
void		c_rotate(t_list **stack);
void		c_reverse_rotate(t_list **stack);
void		c_push(t_list **stack, char dest);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// setup.c
t_list		*insert_on_top(t_list *stack, int number, char c);
t_list		*create_with_string_args(t_list *stack, const char **argv, int i);
t_list		*create_stack(t_list *stack, int argc, const char **argv);
int			stack_size(t_list *stack);
void		freelist(t_list **stack);

// target.c
int			target_max(t_list *stack);
t_list		*targeter(t_list *stack);
int			count_int(t_list *stack);

// utils.c
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// check_errors.c
int			check_double(char const *argv[]);
int			check_errors(char const *argv[]);

// show stacks
void		show_stacks(t_list *stacka, t_list *stackb);

#endif
