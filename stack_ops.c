/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:50 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:52 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*restore_pos(t_list *stack)
{
	int		i;
	t_list	*current;

	i = 1;
	current = stack;
	while (current != NULL)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
	return (stack);
}

t_list	*swap(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL || stack->next == NULL)
		return (NULL);
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;
	stack = restore_pos(stack);
	return (stack);
}

t_list	*rotate(t_list *stack, int ab)
{
	t_list	*last;
	t_list	*tmp;

	last = stack;
	tmp = stack;
	if (stack->next == NULL)
		return (stack);
	stack = stack->next;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	stack = restore_pos(stack);
	if (ab == 0)
		write(1, "ra\n", 3);
	if (ab == 1)
		write(1, "rb\n", 3);
	return (stack);
}

t_list	*reverse_rotate(t_list *stack, int ab)
{
	t_list	*last;
	t_list	*tmp;

	last = stack;
	if (stack->next == NULL)
		return (stack);
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			tmp = last;
		last = last->next;
	}
	last->next = stack;
	tmp->next = NULL;
	last = restore_pos(last);
	if (ab == 0)
		write(1, "rra\n", 4);
	if (ab == 1)
		write(1, "rrb\n", 4);
	return (last);
}

void	push(t_list **stack, char dest)
{
	t_list	*tmp;

	if (dest == 'a' && stack[1] != NULL)
	{
		tmp = stack[1]->next;
		stack[1]->next = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		write(1, "pa\n", 3);
	}
	else if (dest == 'b' && stack[0] != NULL)
	{
		tmp = stack[0]->next;
		stack[0]->next = stack[1];
		stack[1] = stack[0];
		stack[0] = tmp;
		write(1, "pb\n", 3);
	}
	stack[0] = restore_pos(stack[0]);
	stack[1] = restore_pos(stack[1]);
	return ;
}
