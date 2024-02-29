/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:10:03 by jschaft           #+#    #+#             */
/*   Updated: 2023/11/30 11:55:49 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int	word_count(char *str)
{
	int	re;
	int	i;

	i = 0;
	re = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			re++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (re);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *nptr)
{
	int	state;
	int	i;
	int	re;

	state = 1;
	re = 0;
	i = 0;
	if (nptr == NULL)
		return (0);
	if (nptr[0] == '-')
	{
		state = -1;
		i++;
	}
	if (nptr[0] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		re = re * 10;
		re = re + (nptr[i] - 48);
		i++;
	}
	return (re * state);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*null_re;
	char	*re;

	i = 0;
	null_re = malloc(sizeof(char));
	re = malloc(sizeof(char) * (len + 1));
	if (re == NULL || null_re == NULL)
		return (NULL);
	null_re[0] = '\0';
	if (start >= ft_strlen(s))
	{
		free(re);
		return (null_re);
	}
	while (s[i + start] != '\0' && i < (int)len)
	{
		re[i] = s[i + start];
		i++;
	}
	re[i] = '\0';
	free(null_re);
	return (re);
}
