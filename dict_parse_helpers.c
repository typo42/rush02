/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_parse_helpers.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

ssize_t	read_dict_size(int numbers)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	dict_size;
	ssize_t	bytes_read;

	dict_size = 0;
	bytes_read = read(numbers, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		dict_size += bytes_read;
		bytes_read = read(numbers, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		ft_putstr(DICT_ERROR);
		close(numbers);
		return (-1);
	}
	close(numbers);
	return (dict_size);
}

int	get_key_len(char *dict)
{
	int	key_len;

	key_len = 0;
	while (*dict >= '0' && *dict <= '9')
	{
		key_len++;
		dict++;
	}
	return (key_len);
}

char	*skip_to_value(char *dict)
{
	while (*dict >= '0' && *dict <= '9')
		dict++;
	while (*dict == ':' || *dict == ' ')
		dict++;
	return (dict);
}

int	get_value_len(char *dict)
{
	int	value_len;

	value_len = 0;
	dict = skip_to_value(dict);
	while (*dict != '\n' && *dict != '\0' && *dict != '\r')
	{
		value_len++;
		dict++;
	}
	return (value_len);
}

char	*skip_to_line_end(char *dict)
{
	while (*dict != '\n' && *dict != '\0')
		dict++;
	return (dict);
}
