/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   67.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 12:49:32 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:14:23 by fqussay         ###   ########.fr        */
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

char	*lookup(char *k, t_entry *entries, ssize_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(entries[i].key, k) == 0)
			return (entries[i].value);
		i++;
	}
	return (NULL);
}

t_entry	*file_to_array(char *file)
{
	char	*dict;
	t_entry	*entries;

	dict = read_dict(file);
	entries = make_entries_array(dict);
	entries = parse_dict(dict, entries);
	free(dict);
	return (entries);
}

int	put_word(char *s, t_entry *entries, ssize_t size)
{
	char	*word;

	word = lookup(s, entries, size);
	if (word == NULL)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	ft_putstr(word);
	return (0);
}
