/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:26:54 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 09:30:33 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_smallest_index(t_list *stack)
{
	int		i;
	t_list	*tmp_lst;
	int		tmp;
	int		re;

	i = 1;
	tmp_lst = stack;
	re = 1;
	tmp = tmp_lst->nbr;
	while (tmp_lst != NULL)
	{
		if ((tmp_lst->nbr) < tmp)
		{
			re = i;
			tmp = tmp_lst->nbr;
		}
		i++;
		tmp_lst = tmp_lst->next;
	}
	return (re);
}

int	get_biggest_index(t_list *stack)
{
	int		i;
	t_list	*tmp_lst;
	int		tmp;
	int		re;

	if (stack == NULL)
		return (0);
	i = 1;
	tmp_lst = stack;
	re = 1;
	tmp = tmp_lst->nbr;
	while (tmp_lst != NULL)
	{
		if ((tmp_lst->nbr) > tmp)
		{
			re = i;
			tmp = tmp_lst->nbr;
		}
		i++;
		tmp_lst = tmp_lst->next;
	}
	return (re);
}

int	get_second_smallest(t_list *stack, int smallest)
{
	int		i;
	t_list	*tmp_lst;
	int		tmp;
	int		re;

	i = 1;
	tmp_lst = stack;
	if (smallest == 1)
	{
		i++;
		tmp_lst = stack->next;
	}
	re = i;
	tmp = tmp_lst->nbr;
	while (tmp_lst != NULL)
	{
		if ((tmp_lst->nbr) < tmp && i != smallest)
		{
			re = i;
			tmp = tmp_lst->nbr;
		}
		i++;
		tmp_lst = tmp_lst->next;
	}
	return (re);
}

int	get_first_index(t_list *stack, int min, int max)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = stack;
	while (tmp)
	{
		if ((tmp->nbr) >= min && (tmp->nbr) <= max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	get_last_index(t_list *stack, int min, int max)
{
	int		i;
	t_list	*tmp;
	int		re;

	i = 1;
	tmp = stack;
	re = 1;
	while (tmp != NULL)
	{
		if ((tmp->nbr) >= min && (tmp->nbr) <= max)
			re = i;
		i++;
		tmp = tmp->next;
	}
	return (re);
}
