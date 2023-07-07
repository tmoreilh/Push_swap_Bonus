/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:11:34 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:11:36 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **stack)
{
	move_to_b(stack);
	while (stack[1] != NULL)
	{
		stack[0] = upset(stack[0]);
		stack[1] = upset(stack[1]);
		distance_set(stack);
		movers_move(stack);
	}
	stack[0] = upset(stack[0]);
	movers_move(stack);
}

void	move_to_b(t_list **stack)
{
	t_list	*current;
	t_list	*last;
	int		i;

	while (stack_size(stack[0]) > 1)
	{
		i = 1;
		current = stack[0];
		while (current->next != NULL)
		{
			if (current->target < current->next->target)
				i++;
			current = current->next;
		}
		if (i == stack_size(stack[0]))
			break ;
		last = current;
		if (stack[0]->target > last->target)
		{
			stack[0] = rotate(stack[0], 0);
		}
		else
			push(stack, 'b');
	}
	return ;
}

t_list	*min_max_finder(t_list **stack, int x)
{
	t_list	*current[2];
	t_list	*min;
	t_list	*max;

	current[0] = stack[0];
	min = current[0];
	max = current[0];
	while (current[0] != NULL)
	{
		if (current[0]->target > max->target)
			max = current[0];
		if (current[0]->target < min->target)
			min = current[0];
		current[0] = current[0]->next;
	}
	if (x == 0)
		return (min);
	else
		return (max);
}

t_list	*choose_base(t_list **stack)
{
	t_list	*current[2];
	t_list	*min;
	t_list	*max;
	int		i;

	current[0] = stack[0];
	min = min_max_finder(stack, 0);
	max = min_max_finder(stack, 1);
	i = 1;
	if (stack[1] == NULL)
		return (min);
	else
	{
		while (current[0]->target != (stack[1]->target + i))
		{
			current[0] = current[0]->next;
			if (current[0] == NULL)
			{
				if (i++ > max->target)
					return (min);
				current[0] = stack[0];
			}
		}
	}
	return (current[0]);
}

t_list	*choose_mover(t_list *stack)
{
	t_list	*current;
	t_list	*mover;

	current = stack;
	mover = stack;
	while (current != NULL)
	{
		if (current->dist < mover->dist)
			mover = current;
		current = current->next;
	}
	return (mover);
}
