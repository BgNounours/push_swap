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

int	get_len(char *str, int i)
{
	int	re;

	re = 1;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ')
			return (re);
		if (str[i] == '\0')
			return (re);
		re++;
	}
	return (re);
}

int	test_zero(char *s1, char *s2)
{
	if (ft_strcmp(s1, "0") == 0 && ft_strcmp(s2, "-0") == 0)
		return (0);
	if (ft_strcmp(s2, "0") == 0 && ft_strcmp(s1, "-0") == 0)
		return (0);
	return (-1);
}

int	verif_error(int ac, char **av)
{
	char	**av_str;
	int		re;

	if (ac == 2)
	{
		av_str = ft_split(av[1], ' ');
		re = test_tab_str(av_str);
		if (re == -1)
		{
			free_split(av_str);
			return (-1);
		}
		re = verif_double_str(av_str);
		free_split(av_str);
	}
	if (ac > 2)
	{
		re = test_tab(av, ac);
		if (re == -1)
			return (re);
		re = verif_double(av, ac);
	}
	return (re);
}
