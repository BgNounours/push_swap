/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortfh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:16:53 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:48:41 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_divf(int size)
{
	if (size % 10 == 0)
		return (10);
	if (size % 8 == 0)
		return (8);
	if (size % 7 == 0)
		return (7);
	return (5);
}

static t_list	**norm_fh(t_list **stack, int *size)
{
	while (size[1] != 0)
	{
		stack = push_biggest(stack, size[1]);
		size[0]++;
		size[1]--;
	}
	return (stack);
}

t_list	**sort_fhundred(t_list **stack, int *size)
{
	int	max;
	int	div;
	int	i;
	int	i_deux;

	div = get_divf(size[0]);
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
	stack = norm_fh(stack, size);
	return (stack);
}
