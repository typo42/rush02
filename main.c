/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 13:27:18 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 11:49:03 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	*number;

	if (argc < 2 || argc > 3)
	{
		ft_putstr(ERROR);
		return (0);
	}
	file = "numbers.dict";
	number = argv[1];
	if (argc == 3)
	{
		file = argv[1];
		number = argv[2];
	}
	if (!arg_valid(number))
	{
		ft_putstr(ERROR);
		return (0);
	}
	run_conversion(file, number);
	return (0);
}

int	arg_valid(char *arg)
{
	if (!arg || *arg == '\0')
		return (0);
	if (*arg == '0' && *(arg + 1) != '\0')
		return (0);
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (0);
		arg++;
	}
	return (1);
}

int	run_conversion(char *file, char *number)
{
	char	*dict_str;
	ssize_t	n_entries;
	t_entry	*entries;

	dict_str = read_dict(file);
	n_entries = count_entries(dict_str);
	free(dict_str);
	entries = file_to_array(file);
	if (number[0] == '0' && number[1] == '\0')
	{
		ft_putstr(lookup("0", entries, n_entries));
		write(1, "\n", 1);
	}
	else
	{
		if (magic(format(number), entries, n_entries) == 0)
			write(1, "\n", 1);
	}
	free_dict(entries, n_entries);
	return (0);
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
