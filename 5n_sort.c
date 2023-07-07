/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5n_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:11:24 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:11:27 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers_sort(t_list **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack[0]->target < 4)
			stack[0] = rotate(stack[0], 0);
		else
		{
			push(stack, 'b');
			i++;
		}
	}
	stack[0] = three_numbers_sort(stack[0]);
}
