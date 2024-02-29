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

int	ft_strcmp(char *s1, char *s2)
{
	int				i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
