/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:36:58 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:15:52 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	free_all(t_list **stack, int *size)
{
	t_list	*tmp;

	tmp = stack[0];
	while (stack[0] != NULL)
	{
		tmp = stack[0]->next;
		free(stack[0]);
		stack[0] = tmp;
	}
	free(stack);
	free(size);
}
