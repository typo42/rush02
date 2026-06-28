/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   str_utilities.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 13:56:43 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:06:04 by fqussay         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

int	arg_valid(char *arg)
{
	if (!arg || *arg == '\0')
		return (0);
	if (*arg == '0' && *(arg + 1) != '\0')
		return (0);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		arg++;
	}
	return (1);
}

char	*make_string(int size)
{
	char	*string;

	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	return (string);
}
