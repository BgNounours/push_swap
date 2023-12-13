/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:13:41 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:14:17 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static t_list	**another_case(t_list **stack, int i_a, int i_b)
{
	if ((i_a == 2 || i_b == 2) && (i_a == 5 || i_b == 5))
	{
		stack[0] = sa(stack[0]);
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	return (stack);
}

static t_list	**other_other_case(t_list **stack, int i_a, int i_b)
{
	if ((i_a == 1 || i_b == 1) && (i_a == 3 || i_b == 3))
	{
		stack = pb(stack);
		stack[0] = sa(stack[0]);
		stack = pb(stack);
	}
	if ((i_a == 1 || i_b == 1) && (i_a == 4 || i_b == 4))
	{
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	if ((i_a == 2 || i_b == 2) && (i_a == 4 || i_b == 4))
	{
		stack[0] = sa(stack[0]);
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	stack = another_case(stack, i_a, i_b);
	return (stack);
}

static t_list	**other_case(t_list **stack, int i_a, int i_b)
{
	if ((i_a == 4 || i_b == 4) && (i_a == 5 || i_b == 5))
	{
		stack[0] = rra(stack[0]);
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	if ((i_a == 3 || i_b == 3) && (i_a == 4 || i_b == 4))
	{
		stack[0] = rra(stack[0]);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	if ((i_a == 3 || i_b == 3) && (i_a == 5 || i_b == 5))
	{
		stack[0] = rra(stack[0]);
		stack = pb(stack);
		stack[0] = rra(stack[0]);
		stack[0] = rra(stack[0]);
		stack = pb(stack);
	}
	stack = other_other_case(stack, i_a, i_b);
	return (stack);
}

static t_list	**push_smallest(t_list **stack)
{
	int	i_a;
	int	i_b;

	i_a = get_smallest_index(stack[0]);
	i_b = get_second_smallest(stack[0], i_a);
	if ((i_a == 1 || i_b == 1) && (i_a == 2 || i_b == 2))
	{
		stack = pb(stack);
		stack = pb(stack);
	}
	if ((i_a == 3 || i_b == 3) && (i_a == 2 || i_b == 2))
	{
		stack[0] = sa(stack[0]);
		stack = pb(stack);
		stack[0] = sa(stack[0]);
		stack = pb(stack);
	}
	if ((i_a == 1 || i_b == 1) && (i_a == 5 || i_b == 5))
	{
		stack[0] = rra(stack[0]);
		stack = pb(stack);
		stack = pb(stack);
	}
	stack = other_case(stack, i_a, i_b);
	return (stack);
}

t_list	**sort_five(t_list **stack, int size)
{
	if (size == 4)
	{
		stack = sort_ft(stack);
		return (stack);
	}
	stack = push_smallest(stack);
	stack = sort_three(stack);
	stack = pa(stack);
	stack = pa(stack);
	if ((stack[0]->nbr) > (stack[0]->next->nbr))
		stack[0] = sa(stack[0]);
	return (stack);
}
