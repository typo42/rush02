/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	set_input(int argc, char **argv, char **file, char **number)
{
	if (argc == 2)
	{
		*file = "numbers.dict";
		*number = argv[1];
		return ;
	}
	*file = argv[1];
	*number = argv[2];
}

int	load_dict(char *file, t_entry **entries, ssize_t *n_entries)
{
	char	*dict_str;

	dict_str = read_dict(file);
	if (dict_str == NULL)
		return (-1);
	*n_entries = count_entries(dict_str);
	*entries = make_entries_array(dict_str);
	if (*entries == NULL)
	{
		free(dict_str);
		return (-1);
	}
	parse_dict(dict_str, *entries);
	free(dict_str);
	return (0);
}

int	print_number(char *number, t_entry *entries, ssize_t n_entries)
{
	char	*formatted;
	int		ret;

	if (number[0] == '0' && number[1] == '\0')
	{
		ft_putstr(lookup("0", entries, n_entries));
		return (0);
	}
	formatted = format(number);
	if (formatted == NULL)
		return (-1);
	ret = magic(formatted, entries, n_entries);
	if (formatted != number)
		free(formatted);
	return (ret);
}
