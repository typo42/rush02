/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   dict_helpers.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	open_dict_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr(DICT_ERROR);
	return (fd);
}

ssize_t	dict_error(int fd)
{
	ft_putstr(DICT_ERROR);
	if (fd != -1)
		close(fd);
	return (-1);
}

char	*free_read_dict(char *dict, int fd)
{
	free(dict);
	dict_error(fd);
	return (NULL);
}

char	*next_line(char *line)
{
	while (*line && *line != '\n')
		line++;
	if (*line == '\n')
		line++;
	return (line);
}

t_entry	make_entry(char *line)
{
	t_entry	entry;

	entry.key = copy_key(line);
	entry.value = copy_value(line);
	return (entry);
}
