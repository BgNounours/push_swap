/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:16:53 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:28:19 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_div(int size)
{
	if (size % 4 == 0)
		return (4);
	if (size % 3 == 0)
		return (3);
	if (size % 2 == 0)
		return (2);
	return (1);
}

t_list	**push_biggest(t_list **stack, int size)
{
	int	move;
	int	index;

	index = get_biggest_index(stack[1]);
	move = nbr_to_move(index, size);
	while (move > 0)
	{
		if (index > size / 2)
			stack[1] = rrb(stack[1]);
		if (index <= size / 2)
			stack[1] = rb(stack[1]);
		move--;
	}
	stack = pa(stack);
	return (stack);
}

static t_list	**norm_h(t_list **stack, int *size, int max, int div)
{
	while (size[1] != 0)
	{
		while (size[1] != max - div)
		{
			stack = push_biggest(stack, size[1]);
			size[0]++;
			size[1]--;
		}
		max -= div;
	}
	return (stack);
}

t_list	**sort_hundred(t_list **stack, int *size)
{
	int	max;
	int	div;

	div = get_div(size[0]);
	max = size[0] / div;
	div = max;
	while (size[0] != 0)
	{
		while (size[1] != max)
		{
			stack = push_closest(stack, max - div, max, size[0]);
			size[0]--;
			size[1]++;
		}
		max += div;
	}
	stack = norm_h(stack, size, max, div);
	return (stack);
}
