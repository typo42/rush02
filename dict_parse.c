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
	int	numbers;

	numbers = open(file, O_RDONLY);
	if (numbers == -1)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	return (read_dict_size(numbers));
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
	int		k;
	int		n_entries;
	int		key_len;
	int		value_len;

	n_entries = count_entries(dict);
	k = 0;
	while (k < n_entries)
	{
		while (*dict != '\n' && *dict != '\0')
		{
			key_len = get_key_len(dict);
			value_len = get_value_len(dict);
			entries[k].key = copy_key(dict, key_len);
			entries[k].value = copy_value(dict, value_len);
			while (*dict != '\n' && *dict != '\0')
				dict++;
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
		ft_putstr(DICT_ERROR);
		close(numbers);
		return (NULL);
	}
	close(numbers);
	return (dict);
}
