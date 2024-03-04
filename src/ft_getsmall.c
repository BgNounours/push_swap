/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsmall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:26:54 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 09:30:33 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_nb(t_list *stack, int nb)
{
	t_list	*tmp;
	int		re;

	re = 2147483647;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->nbr > nb && tmp->nbr < re)
			re = tmp->nbr;
		tmp = tmp->next;
	}
	return (re);
}

int	get_nb_small(t_list *stack, int ministack)
{
	int	nb;
	int	i;

	nb = -2147483648;
	i = 0;
	while (i < ministack)
	{
		nb = get_nb(stack, nb);
		i++;
	}
	return (nb);
}
