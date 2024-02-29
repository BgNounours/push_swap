/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:31:36 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 09:30:32 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_list	*ft_lstnew(int n_nbr)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = n_nbr;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int			i;
	t_list		*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_lstsorted(t_list *lst)
{
	t_list	*tmp;
	int		nbr;

	tmp = lst->next;
	nbr = lst->nbr;
	while (tmp)
	{
		if ((tmp->nbr) < nbr)
			return (0);
		nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	printf("\n");
}
