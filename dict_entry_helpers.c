/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_entry_helpers.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*copy_key(char *pos, int key_len)
{
	char	*key;
	int		i;

	key = make_string(key_len);
	i = 0;
	while (*pos >= '0' && *pos <= '9')
	{
		key[i] = *pos;
		i++;
		pos++;
	}
	key[i] = '\0';
	return (key);
}

char	*copy_value(char *pos, int value_len)
{
	char	*value;
	int		i;

	value = make_string(value_len);
	pos = skip_to_value(pos);
	i = 0;
	while (*pos != '\n' && *pos != '\0' && *pos != '\r')
	{
		value[i] = *pos;
		i++;
		pos++;
	}
	value[i] = '\0';
	return (value);
}

t_entry	parse_entry(char *dict)
{
	t_entry	entry;
	int		key_len;
	int		value_len;

	key_len = get_key_len(dict);
	value_len = get_value_len(dict);
	entry.key = copy_key(dict, key_len);
	entry.value = copy_value(dict, value_len);
	return (entry);
}
