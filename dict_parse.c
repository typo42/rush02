/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_parse.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/26 22:34:25 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 11:49:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

ssize_t	get_dict_size(char *file)
{
	int		numbers;
	char	buffer[BUFFER_SIZE];
	ssize_t	dict_size;
	ssize_t	bytes_read;

	numbers = open_dict_file(file);
	if (numbers == -1)
		return (-1);
	dict_size = 0;
	bytes_read = read(numbers, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		dict_size += bytes_read;
		bytes_read = read(numbers, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (dict_error(numbers));
	close(numbers);
	return (dict_size);
}

int	count_entries(char *dict)
{
	int	entries;

	entries = 0;
	while (*dict)
	{
		if (*dict == ':')
			entries++;
		dict++;
	}
	return (entries);
}

t_entry	*parse_dict(char *dict, t_entry *entries)
{
	int	k;
	int	size;

	size = count_entries(dict);
	k = 0;
	while (k < size && *dict != '\0')
	{
		if (*dict != '\n')
		{
			entries[k] = make_entry(dict);
			k++;
		}
		dict = next_line(dict);
	}
	return (entries);
}

t_entry	*make_entries_array(char *dict)
{
	int		entries_count;
	t_entry	*entries;

	entries_count = count_entries(dict);
	entries = malloc(sizeof(t_entry) * entries_count);
	if (entries == NULL)
		return (NULL);
	return (entries);
}

char	*read_dict(char *file)
{
	int		numbers;
	char	*dict;
	ssize_t	dict_size;

	dict_size = get_dict_size(file);
	if (dict_size < 0)
		return (NULL);
	dict = malloc(dict_size + 1);
	if (dict == NULL)
		return (NULL);
	numbers = open_dict_file(file);
	if (numbers == -1)
		return (free_read_dict(dict, numbers));
	if (read(numbers, dict, dict_size) == -1)
		return (free_read_dict(dict, numbers));
	dict[dict_size] = '\0';
	close(numbers);
	return (dict);
}
