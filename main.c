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

int	main(int argc, char **argv)
{
	char	*file;
	char	*number;
	ssize_t	n_entries;
	t_entry	*entries;

	if (argc < 2 || argc > 3)
	{
		ft_putstr(ERROR);
		return (0);
	}
	set_input(argc, argv, &file, &number);
	if (!arg_valid(number))
	{
		ft_putstr(ERROR);
		return (0);
	}
	if (load_dict(file, &entries, &n_entries) == -1)
		return (0);
	if (print_number(number, entries, n_entries) == 0)
		write(1, "\n", 1);
	free_dict(entries, n_entries);
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
