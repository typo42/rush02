/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 13:27:18 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:26:16 by fqussay         ###   ########.fr        */
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
	char	*dict_str;
	ssize_t	n_entries;
	t_entry	*entries;

	if (argc < 2 || argc > 3)
	{
		ft_putstr(ERROR);
		return (0);
	}
	if (argc == 2)
	{
		file = "numbers.dict";
		number = argv[1];
	}
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
	dict_str = read_dict(file);
	n_entries = count_entries(dict_str);
	free(dict_str);
	entries = file_to_array(file);
	if (number[0] == '0' && number[1] == '\0')
	{
		ft_putstr(lookup("0", entries, n_entries));
		write(1, "\n", 1);
		free_dict(entries, n_entries);
	}
	else if (magic(format(number), file_to_array(file), n_entries) == 0)
		write(1, "\n", 1);
}
