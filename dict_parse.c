/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_parse.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/26 22:34:25 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:33:58 by fqussay         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

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
	k = 0;
	while (k < size)
	{
		while (*dict != '\n' && *dict != '\0')
		{
			pos = dict;
			key_len = 0;
			value_len = 0;
			while (*dict >= '0' && *dict <= '9')
			{
				key_len++;
				dict++;
			}
			while (*dict == ':' || *dict == ' ')
				dict++;
			while (*dict != '\n' && *dict != '\0' && *dict != '\r')
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
			while (*pos != '\n' && *pos != '\0' && *pos != '\r')
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
