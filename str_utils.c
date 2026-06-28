/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   str_utils.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 13:56:43 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 11:49:08 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*format(char *input)
{
	int		r;
	char	*formatted;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(input);
	r = len % 3;
	if (r == 0)
		return (input);
	formatted = malloc(len + (3 - r) + 1);
	while (i < (3 - r))
		formatted[i++] = '0';
	while (*input)
		formatted[i++] = *input++;
	formatted[i] = '\0';
	return (formatted);
}

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

char	*make_string(int size)
{
	char	*string;

	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	return (string);
}
