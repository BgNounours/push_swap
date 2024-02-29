/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:07:26 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:00 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static t_list	*fill_first_stack(int ac, char **av)
{
	t_list	*re;
	t_list	*tmp;
	int		i;

	i = 1;
	re = ft_lstnew(ft_atoi(av[i]));
	tmp = re;
	i++;
	while (i < ac)
	{
		tmp->next = ft_lstnew(ft_atoi(av[i]));
		tmp = tmp->next;
		i++;
	}
	return (re);
}

static t_list	*fill_from_str(char *str)
{
	char	**tab;
	t_list	*tmp;
	t_list	*re;
	int		i;

	tab = ft_split(str, ' ');
	i = 1;
	re = ft_lstnew(ft_atoi(tab[0]));
	tmp = re;
	while (tab[i] != NULL)
	{
		tmp->next = ft_lstnew(ft_atoi(tab[i]));
		tmp = tmp->next;
		i++;
	}
	free_split(tab);
	return (re);
}

static void	norm_main(t_list **stack, int *size)
{
	size[0] = ft_lstsize(stack[0]);
	size[1] = 0;
	size[2] = size[0];
	if (size[0] == 2)
		stack = complete_at_two(stack);
	if (size[0] == 3)
		stack = sort_three(stack);
	if (size[0] <= 5 && size[0] > 3)
		stack = sort_five(stack, size[0]);
	if (size[0] <= 100 && size[0] > 5)
		stack = sort_hundred(stack, size);
	if (size[0] > 100)
		stack = sort_fhundred(stack, size);
}

int	main(int ac, char **av)
{
	t_list	**stack;
	int		*size;

	if (ac <= 1)
		return (0);
	if (verif_error(ac, av) < 0)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	stack = malloc(sizeof(t_list *) * 2);
	size = malloc(sizeof(int) * 3);
	if (ac != 2)
		stack[0] = fill_first_stack(ac, av);
	else
		stack[0] = fill_from_str(av[1]);
	if (stack[0] == NULL || ft_lstsorted(stack[0]) == 1)
	{
		free_all(stack, size);
		return (0);
	}
	stack[1] = NULL;
	norm_main(stack, size);
	free_all(stack, size);
}
