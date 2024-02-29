/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:02:41 by jschaft           #+#    #+#             */
/*   Updated: 2023/11/20 10:56:38 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static int	test_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	if (str[i] != '-' && str[i] != '+' && (str[i] > '9' || str[i] < '0'))
		return (-1);
	i++;
	if (ft_strlen(str) == 1 && str[0] == '+'
		|| ft_strlen(str) == 1 && str[0] == '-')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (1);
}

int	test_tab(char **tab, int ac)
{
	int	y;

	y = 1;
	while (y < ac)
	{
		if (ft_strlen(tab[y]) > 10)
			return (-1);
		if (test_str(tab[y]) < 0)
			return (-1);
		y++;
	}
	return (1);
}

int	test_tab_str(char **tab)
{
	int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		if (ft_strlen(tab[y]) > 10)
			return (-1);
		if (test_str(tab[y]) < 0)
			return (-1);
		y++;
	}
	return (1);
}

int	verif_double(char **tab, int ac)
{
	int	y;
	int	x;

	y = 1;
	x = y + 1;
	while (y < ac - 1)
	{
		while (x < ac)
		{
			if (ft_strcmp(tab[y], tab[x]) == 0)
				return (-1);
			if (test_zero(tab[y], tab[x]) == 0)
				return (-1);
			x++;
		}
		y++;
		x = y + 1;
	}
	return (1);
}

int	verif_double_str(char **tab)
{
	int	y;
	int	x;

	y = 0;
	x = y + 1;
	while (tab[y + 1] != NULL)
	{
		while (tab[x] != NULL)
		{
			if (ft_strcmp(tab[y], tab[x]) == 0)
				return (-1);
			if (test_zero(tab[y], tab[x]) == 0)
				return (-1);
			x++;
		}
		y++;
		x = y + 1;
	}
	return (1);
}
