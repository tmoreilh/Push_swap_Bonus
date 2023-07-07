/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:14:39 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:14:40 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	swaper(char *str, t_list **stackA, t_list **stackB)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		c_swap(stackA);
	if (ft_strncmp(str, "sb", 3) == 0)
		c_swap(stackB);
	if (ft_strncmp(str, "ss", 3) == 0)
	{
		c_swap(stackA);
		c_swap(stackB);
	}
}

void	do_the_move(char *str, t_list **stack, t_list **stackA, t_list **stackB)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		c_push(stack, 'a');
	if (ft_strncmp(str, "pb", 2) == 0)
		c_push(stack, 'b');
	if (ft_strncmp(str, "ra", 2) == 0)
		c_rotate(stackA);
	if (ft_strncmp(str, "rb", 2) == 0)
		c_rotate(stackB);
	if (ft_strncmp(str, "rr", 3) == 0)
	{
		c_rotate(stackA);
		c_rotate(stackB);
	}
	if (ft_strncmp(str, "rra", 3) == 0)
		c_reverse_rotate(stackA);
	if (ft_strncmp(str, "rrb", 3) == 0)
		c_reverse_rotate(stackB);
	if (ft_strncmp(str, "rrr", 3) == 0)
	{
		c_reverse_rotate(stackA);
		c_reverse_rotate(stackB);
	}
	else
		swaper(str, stackA, stackB);
}

void	isokay(t_list **stack)
{
	t_list	*current;

	current = stack[0];
	if (stack[1] != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (current != NULL)
	{
		if (current->pos != current->target)
		{
			write(1, "KO\n", 3);
			current = stack[0];
			return ;
		}
		current = current->next;
	}
	write(1, "OK\n", 3);
	return ;
}

int	check_valid_arg(char *str)
{
	if (ft_strncmp(str, "sa", 3) == 0 || ft_strncmp(str, "sb", 3) == 0
		|| ft_strncmp(str, "ss", 3) == 0 || ft_strncmp(str, "pa", 3) == 0
		|| ft_strncmp(str, "pb", 3) == 0 || ft_strncmp(str, "ra", 3) == 0
		|| ft_strncmp(str, "rb", 3) == 0 || ft_strncmp(str, "rr", 3) == 0
		|| ft_strncmp(str, "rra", 4) == 0 || ft_strncmp(str, "rrb", 4) == 0
		|| ft_strncmp(str, "rrr", 4) == 0)
		return (0);
	else
		write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_list	*stack[2];
	int		fd;
	char	*line;

	fd = 0;
	if (check_errors(argv) < 0)
		return (1);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_valid_arg(line))
			return (-1);
		do_the_move(line, stack, &stack[0], &stack[1]);
		free(line);
	}
	free(line);
	isokay(stack);
	freelist(stack);
	return (0);
}
