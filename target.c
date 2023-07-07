/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:57 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:58 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_target_one(t_list *stack)
{
	t_list	*current;
	int		last_assigned;

	current = stack;
	last_assigned = current->value;
	while (current != NULL)
	{
		if (current->value < last_assigned)
		{
			last_assigned = current->value;
			current->target = 1;
		}
		current = current->next;
	}
	return (last_assigned);
}

int	target_max(t_list *stack)
{
	int		max;
	t_list	*current;

	current = stack;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_last_assigned_target(t_list *stack, int max, int last_assigned)
{
	int		tmp;
	t_list	*current;

	tmp = max;
	current = stack;
	while (current != NULL)
	{
		if (current->value > last_assigned && current->value < tmp)
			tmp = current->value;
		current = current->next;
	}
	last_assigned = tmp;
	return (last_assigned);
}

int	count_int(t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_list	*targeter(t_list *stack)
{
	int		i;
	int		max;
	int		last_assigned;
	t_list	*current;

	i = 1;
	current = stack;
	current->target = i;
	last_assigned = current->value;
	max = current->value;
	last_assigned = set_target_one(stack);
	max = target_max(stack);
	while (i++ <= count_int(stack))
	{
		current = stack;
		while (current != NULL)
		{
			if (current->value > last_assigned && current->value <= max)
				current->target = i;
			current = current->next;
		}
		current = stack;
		last_assigned = find_last_assigned_target(stack, max, last_assigned);
	}
	return (stack);
}
