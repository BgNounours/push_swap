/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushclose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:05:58 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:31:28 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbr_to_move(int i, int size)
{
	int	re;

	if (i > (size / 2))
		re = (size - i) + 1;
	if (i <= (size / 2))
		re = i - 1;
	return (re);
}

static char	closest(int a, int b, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (a > (size / 2))
		i = size - a + 1;
	if (a < (size / 2))
		i = a - 1;
	if (b > (size / 2))
		j = size - b + 1;
	if (b < (size / 2))
		j = b - 1;
	if (i > j)
		return ('b');
	return ('a');
}

static t_list	**moving(t_list **stack, int i, int size, int max)
{
	int	nb_move;

	nb_move = nbr_to_move(i, size);
	while (nb_move > 0)
	{
		if (i > (size / 2))
			stack[0] = rra(stack[0]);
		if (i < (size / 2))
			stack[0] = ra(stack[0]);
		nb_move--;
	}
	stack = pb(stack);
	return (stack);
}

t_list	**push_closest(t_list **stack, int min, int max, int size)
{
	int	i_a;
	int	i_b;
	int	nb_move;

	i_a = get_first_index(stack[0], min, max);
	i_b = get_last_index(stack[0], min, max);
	if (closest(i_a, i_b, size) == 'a')
		stack = moving(stack, i_a, size, max);
	if (closest(i_a, i_b, size) == 'b')
		stack = moving(stack, i_b, size, max);
	return (stack);
}
