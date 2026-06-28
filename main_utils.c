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

void	set_file_and_number(int argc, char **argv, char **file, char **number)
{
	if (argc == 2)
	{
		*file = "numbers.dict";
		*number = argv[1];
	}
	if (argc == 3)
	{
		*file = argv[1];
		*number = argv[2];
	}
}

int	print_zero(t_entry *entries, ssize_t n_entries)
{
	ft_putstr(lookup("0", entries, n_entries));
	write(1, "\n", 1);
	free_dict(entries, n_entries);
	return (0);
}

int	print_nonzero(char *file, char *number, ssize_t n_entries)
{
	if (magic(format(number), file_to_array(file), n_entries) == 0)
		write(1, "\n", 1);
	return (0);
}

int	run_conversion(char *file, char *number)
{
	char	*dict_str;
	ssize_t	n_entries;
	t_entry	*entries;

	if (!arg_valid(number))
	{
		ft_putstr(ERROR);
		return (0);
	}
	dict_str = read_dict(file);
	n_entries = count_entries(dict_str);
	free(dict_str);
	entries = file_to_array(file);
	if (number[0] == '0' && number[1] == '\0')
		return (print_zero(entries, n_entries));
	print_nonzero(file, number, n_entries);
	return (0);
}
