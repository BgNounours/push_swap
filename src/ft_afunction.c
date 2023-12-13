/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:40:36 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/06 12:16:38 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>

t_list	*sa(t_list *stack)
{
	t_list	*tmp;
	t_list	*next;

	ft_putstr("sa\n");
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

t_list	*ra(t_list *stack)
{
	t_list	*next;
	t_list	*re;

	ft_putstr("ra\n");
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

t_list	*rra(t_list *stack)
{
	t_list	*tmp;
	t_list	*re;

	ft_putstr("rra\n");
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

t_list	**pa(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_a;

	ft_putstr("pa\n");
	if (stack == NULL)
		return (NULL);
	if (stack[1] == NULL)
		return (stack);
	tmp = stack[1]->next;
	tmp_a = stack[0];
	stack[0] = stack[1];
	stack[0]->next = tmp_a;
	stack[1] = tmp;
	return (stack);
}
