/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_copy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	key_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	return (i);
}

char	*value_start(char *line)
{
	while (*line >= '0' && *line <= '9')
		line++;
	while (*line == ':' || *line == ' ')
		line++;
	return (line);
}

int	value_size(char *line)
{
	char	*value;
	int		i;

	value = value_start(line);
	i = 0;
	while (value[i] != '\n' && value[i] != '\0' && value[i] != '\r')
		i++;
	return (i);
}

char	*copy_key(char *line)
{
	char	*key;
	int		i;

	key = make_string(key_size(line));
	if (key == NULL)
		return (NULL);
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		key[i] = line[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*copy_value(char *line)
{
	char	*value;
	char	*pos;
	int		i;

	pos = value_start(line);
	value = make_string(value_size(line));
	if (value == NULL)
		return (NULL);
	i = 0;
	while (pos[i] != '\n' && pos[i] != '\0' && pos[i] != '\r')
	{
		value[i] = pos[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}
