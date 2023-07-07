/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:41 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:44 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*insert_on_top(t_list *stack, int number, char c)
{
	t_list	*new;
	t_list	*current[2];

	current[0] = stack;
	current[1] = NULL;
	if (number == 0 && c != '0')
	{
		write(2, "Error\n", 6);
		freelist(current);
		return (stack);
	}
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	new->value = number;
	new->next = stack;
	stack = new;
	return (stack);
}

t_list	*create_stack(t_list *stack, int argc, const char **argv)
{
	int		i;

	i = 0;
	if (argc >= 2)
	{
		i = argc - 1;
		while (i > 0)
		{
			stack = insert_on_top(stack, ft_atoi(argv[i]), argv[i][0]);
			stack->pos = i--;
		}
	}
	stack = targeter(stack);
	return (stack);
}

int	stack_size(t_list *stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	freelist(t_list **stack)
{
	t_list	*current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	while (current[0] != NULL)
	{
		current[0] = current[0]->next;
		free(stack[0]);
		stack[0] = current[0];
	}
	free(current[0]);
	while (current[1] != NULL)
	{
		current[1] = current[1]->next;
		free(stack[0]);
		stack[1] = current[1];
	}
	free(current[1]);
	exit(1);
	return ;
}
