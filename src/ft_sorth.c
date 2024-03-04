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

static t_list	**norm_h(t_list **stack, int *size)
{
	while (size[1] != 0)
	{
		stack = push_biggest(stack, size[1]);
		size[0]++;
		size[1]--;
	}
	return (stack);
}

t_list	**sort_hundred(t_list **stack, int *size)
{
	int	max;
	int	div;
	int	i;
	int	i_deux;

	div = get_div(size[0]);
	i = size[0] / div;
	i_deux = i;
	max = get_nb_small(stack[0], i_deux);
	while (size[0] != 0)
	{
		while (size[1] != i)
		{
			stack = push_closest(stack, -10000000, max, size[0]);
			size[0]--;
			size[1]++;
		}
		max = get_nb_small(stack[0], i_deux);
		i += i_deux;
	}
	stack = norm_h(stack, size);
	return (stack);
}
