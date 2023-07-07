/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:13:39 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:13:40 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	c_swap(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
	*stack = restore_pos(*stack);
	return ;
}

void	c_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (!*stack)
		return ;
	last = *stack;
	tmp = *stack;
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	*stack = restore_pos(*stack);
	return ;
}

void	c_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (!*stack)
		return ;
	last = *stack;
	if ((*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			tmp = last;
		last = last->next;
	}
	last->next = *stack;
	tmp->next = NULL;
	last = restore_pos(last);
	*stack = last;
	return ;
}

void	c_push(t_list **stack, char dest)
{
	t_list	*tmp;

	if (dest == 'a' && stack[1] != NULL)
	{
		tmp = stack[1]->next;
		stack[1]->next = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
	else if (dest == 'b' && stack[0] != NULL)
	{
		tmp = stack[0]->next;
		stack[0]->next = stack[1];
		stack[1] = stack[0];
		stack[0] = tmp;
	}
	stack[0] = restore_pos(stack[0]);
	stack[1] = restore_pos(stack[1]);
	return ;
}
