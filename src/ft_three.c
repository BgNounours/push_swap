/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:26:15 by jschaft           #+#    #+#             */
/*   Updated: 2023/11/24 11:05:36 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	case_ff(t_list **stack, int a, int b, int c)
{
	if (a < b && a < c && b > c)
	{
		stack[0] = sa(stack[0]);
		stack[0] = ra(stack[0]);
	}
	if (a > c && a < b)
		stack[0] = rra(stack[0]);
}

static void	case_double(t_list **stack, int a, int b, int c)
{
	if ((a == b && a < c) || (a == b && b == c) || (a < b && b == c))
		return ;
	if (a == c && b < a)
		stack[0] = sa(stack[0]);
	if (a == c && b > a)
		stack[0] = rra(stack[0]);
	if (b == c && a > b)
		stack[0] = ra(stack[0]);
	if (a == b && c < a)
		stack[0] = rra(stack[0]);
}

t_list	**sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = stack[0]->nbr;
	b = stack[0]->next->nbr;
	c = stack[0]->next->next->nbr;
	if (a < b && b < c)
		return (stack);
	if (a > b && a < c && b < c)
		stack[0] = sa(stack[0]);
	if (a > b && b > c)
	{
		stack[0] = sa(stack[0]);
		stack[0] = rra(stack[0]);
	}
	if (a > b && a > c && b < c)
		stack[0] = ra(stack[0]);
	case_ff(stack, a, b, c);
	case_double(stack, a, b, c);
	return (stack);
}
