/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:40 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:08:36 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	**complete_at_two(t_list **stack)
{
	int		nb;
	t_list	*tmp;

	if (stack[0]->next->nbr == 0)
		return (stack);
	tmp = stack[0]->next;
	nb = tmp->nbr;
	if (nb >= stack[0]->nbr)
		return (0);
	stack[0] = sa(stack[0]);
	return (stack);
}

t_list	**sort_ft(t_list **stack)
{
	int	i;

	if (stack[0]->next->nbr == 0 && stack[0]->next->next->nbr == 0)
		return (stack);
	i = get_smallest_index(stack[0]);
	if (i == 2)
		stack[0] = sa(stack[0]);
	if (i == 3)
	{
		stack[0] = ra(stack[0]);
		stack[0] = ra(stack[0]);
	}
	if (i == 4)
		stack[0] = rra(stack[0]);
	stack = pb(stack);
	stack = sort_three(stack);
	stack = pa(stack);
	return (stack);
}
