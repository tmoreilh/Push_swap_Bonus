/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:01 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:03 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*upset(t_list *stack)
{
	t_list	*current;
	int		size;

	size = stack_size(stack);
	current = stack;
	while (current != NULL)
	{
		current->up = isup(current->pos, size);
		current = current->next;
	}
	return (stack);
}

int	isup(int pos, int size)
{
	if ((size / 2) >= pos)
		return (1);
	else
		return (0);
}

void	distance_set(t_list **stack)
{
	t_list	*current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	while (current[1] != NULL)
	{
		current[1]->dist = distance_calculator(current, \
		stack_size(stack[0]), stack_size(stack[1]));
		current[1] = current[1]->next;
	}
	return ;
}

int	optimizator(t_list *base, t_list *stackB, int sizeA, int sizeB)
{
	int	t;

	t = 0;
	if (stackB->up == 1)
	{
		if (base->up == 1)
		{
			if (stackB->pos <= base->pos)
				t = stackB->pos - 1;
			else
				t = base->pos - 1;
		}
	}
	else
	{
		if (base->up != 1)
		{
			if ((sizeB - stackB->pos + 1) <= (sizeA - base->pos + 1))
				t = (sizeB - stackB->pos + 1);
			else
				t = (sizeA - base->pos + 1);
		}
	}
	return (t);
}

int	distance_calculator(t_list **stack, int sizeA, int sizeB)
{
	t_list	*base;
	int		d;
	int		t;

	base = choose_base(stack);
	t = optimizator(base, stack[1], sizeA, sizeB);
	if (stack[1]->up == 1)
	{
		if (base->up == 1)
			d = stack[1]->pos - 1 + base->pos - 1 - t;
		else
			d = stack[1]->pos - 1 + sizeA - base->pos + 1;
	}
	else
	{
		if (base->up == 1)
			d = sizeB - stack[1]->pos + 1 + base->pos - 1;
		else
			d = (sizeB - stack[1]->pos + 1) + (sizeA - base->pos + 1) - t;
	}
	return (d);
}
