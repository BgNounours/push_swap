/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:40:36 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/06 12:16:29 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

t_list	*sb(t_list *stack)
{
	t_list	*tmp;
	t_list	*next;

	ft_putstr("sb\n");
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	tmp = stack->next;
	next = tmp->next;
	stack->next = next;
	tmp->next = stack;
	return (tmp);
}

t_list	*rb(t_list *stack)
{
	t_list	*next;
	t_list	*re;

	ft_putstr("rb\n");
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	re = stack->next;
	next = stack;
	while (stack->next != NULL)
		stack = stack->next;
	next->next = NULL;
	stack->next = next;
	return (re);
}

t_list	*rrb(t_list *stack)
{
	t_list	*tmp;
	t_list	*re;

	ft_putstr("rrb\n");
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	tmp = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	re = stack->next;
	re->next = tmp;
	stack->next = NULL;
	return (re);
}

t_list	**pb(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_a;

	ft_putstr("pb\n");
	if (stack == NULL)
		return (NULL);
	if (stack[0] == NULL)
		return (stack);
	tmp = stack[0]->next;
	tmp_a = stack[1];
	stack[1] = stack[0];
	stack[1]->next = tmp_a;
	stack[0] = tmp;
	return (stack);
}
