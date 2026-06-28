/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   entries_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 12:49:32 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 12:35:47 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*lookup(char *k, t_entry *entries, ssize_t n_entries)
{
	int	i;

	i = 0;
	while (i < n_entries)
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

int	put_word(char *s, t_entry *entries, ssize_t n_entries)
{
	char	*word;

	word = lookup(s, entries, n_entries);
	if (word == NULL)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	ft_putstr(word);
	return (0);
}

char	*make_word(char first, char second, int len)
{
	char	*word;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	word[0] = first;
	if (len == 2)
		word[1] = second;
	word[len] = '\0';
	return (word);
}

char	*make_triplet(char *number)
{
	char	*triplet;

	triplet = malloc(4);
	if (triplet == NULL)
		return (NULL);
	triplet[0] = number[0];
	triplet[1] = number[1];
	triplet[2] = number[2];
	triplet[3] = '\0';
	return (triplet);
}
