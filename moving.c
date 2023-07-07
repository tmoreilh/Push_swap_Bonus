/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:12:23 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:12:24 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_moves(t_list **stack, int *i, int *j)
{
	while (*i > 1 && *j > 1 && stack[1] != NULL)
	{
		stack[0] = rotate(stack[0], 3);
		stack[1] = rotate(stack[1], 3);
		(*i)--;
		(*j)--;
		write(1, "rr\n", 3);
	}
	while (*i < 1 && *j < 1 && stack[1] != NULL)
	{
		stack[0] = reverse_rotate(stack[0], 3);
		stack[1] = reverse_rotate(stack[1], 3);
		(*i)++;
		(*j)++;
		write(1, "rrr\n", 4);
	}
}

void	good_moves(t_list **stack, int i, int j)
{
	double_moves(stack, &i, &j);
	while (i > 1)
	{
		stack[0] = rotate(stack[0], 0);
		i--;
	}
	while (i < 1)
	{
		stack[0] = reverse_rotate(stack[0], 0);
		i++;
	}
	while (j > 1 && stack[1] != NULL)
	{
		stack[1] = rotate(stack[1], 1);
		j--;
	}
	while (j < 1 && stack[1] != NULL)
	{
		stack[1] = reverse_rotate(stack[1], 1);
		j++;
	}
	return ;
}

void	movers_move(t_list **stack)
{
	t_list	*mover;
	t_list	*base;
	t_list	*current[2];
	int		i;
	int		j;

	mover = NULL;
	j = 0;
	if (stack[1] != NULL)
		mover = choose_mover(stack[1]);
	current[0] = stack[0];
	current[1] = mover;
	base = choose_base(current);
	if (base->up == 1)
		i = base->pos;
	else
		i = base->pos - stack_size(stack[0]);
	if (stack[1] != NULL && mover->up == 1)
		j = mover->pos;
	else if (stack[1] != NULL)
		j = mover->pos - stack_size(stack[1]);
	good_moves(stack, i, j);
	push(stack, 'a');
	return ;
}
