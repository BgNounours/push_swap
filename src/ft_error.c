/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:02:41 by jschaft           #+#    #+#             */
/*   Updated: 2023/11/20 10:56:38 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	ft_perror(const char *str)
{
	int	i;

	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	verif_error(int ac, char **av)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (y < ac)
	{
		if (av[y][i] == '-' || av[y][i] == '+')
			i++;
		while (av[y][i] != '\0')
		{
			if (av[y][i] != ' ' && (av[y][i] < '0' || av[y][i] > '9'))
			{
				ft_perror("ERROR: please give NUMBERS ONLY as arguments\n");
				return (-1);
			}
			i++;
		}
		i = 0;
		y++;
	}
	return (1);
}
