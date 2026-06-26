/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rush02.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/26 22:34:25 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/27 00:36:24 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "rush02.h"

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

char	*make_string(int size)
{
	char	*string;

	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	return (string);
}

t_entry	*parse_dict(char *dict, t_entry *entries)
{
	int		key_len;
	int		value_len;
	char	*pos;
	t_entry	entry;
	int		i;
	int		k;
	int		size;

	size = count_entries(dict);
	pos = dict;
	k = 0;
	while (k < size)
	{
		while (*dict != '\n')
		{
			key_len = 0;
			value_len = 0;
			while (*dict >= '0' && *dict <= '9')
			{
				key_len++;
				dict++;
			}
			while (*dict == ':' || *dict == ' ')
				dict++;
			while (*dict >= 'a' && *dict <= 'z')
			{
				value_len++;
				dict++;
			}
			entry.key = make_string(key_len);
			entry.value = make_string(value_len);
			i = 0;
			while (*pos >= '0' && *pos <= '9')
			{
				entry.key[i] = *pos;
				i++;
				pos++;
			}
			entry.key[i] = '\0';
			while (*pos == ':' || *pos == ' ')
				pos++;
			i = 0;
			while (*pos >= 'a' && *pos <= 'z')
			{
				entry.value[i] = *pos;
				i++;
				pos++;
			}
			entry.value[i] = '\0';
			entries[k] = entry;
			k++;
		}
		dict++;
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

ssize_t	get_dict_size(char *file)
{
	int		numbers;
	char	buffer[BUFFER_SIZE];
	ssize_t	dict_size;
	ssize_t	bytes_read;

	numbers = open(file, O_RDONLY);
	if (numbers == -1)
	{
		printf("Dict Error\n");
		return (-1);
	}
	dict_size = 0;
	bytes_read = read(numbers, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		dict_size += bytes_read;
		bytes_read = read(numbers, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		printf("Dict Error\n");
		close(numbers);
		return (-1);
	}
	close(numbers);
	return (dict_size);
}

char	*read_dict(char *file)
{
	int		numbers;
	char	*dict;
	ssize_t	dict_size;
	ssize_t	bytes_read;

	dict_size = get_dict_size(file);
	dict = malloc(dict_size + 1);
	if (dict == NULL)
		return (NULL);
	dict[dict_size] = '\0';
	numbers = open(file, O_RDONLY);
	bytes_read = read(numbers, dict, dict_size);
	if (bytes_read == -1)
	{
		printf("Dict Error\n");
		close(numbers);
		return (NULL);
	}
	close(numbers);
	return (dict);
}

int	main(int argc, char **argv)
{
	char	*dict;
	char	*file;
	t_entry	*entries;

	file = "numbers.dict";
	dict = read_dict(file);
	entries = make_entries_array(dict);
	entries = parse_dict(dict, entries);
	printf("%s\n", entries[0].key);
	printf("%s\n", entries[0].value);
	return (0);
}
