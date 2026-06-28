/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   entries_utils_2.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 16:32:33 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 16:32:33 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_longest_key_len(t_entry *entries, ssize_t n_entries)
{
	ssize_t	i;
	int		longest;
	int		key_len;

	i = 0;
	longest = 0;
	while (i < n_entries)
	{
		key_len = ft_strlen(entries[i].key);
		if (key_len > longest)
			longest = key_len;
		i++;
	}
	return (longest);
}

void	free_dict(t_entry *entries, ssize_t n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		free(entries[i].key);
		free(entries[i].value);
		i++;
	}
	free(entries);
}
