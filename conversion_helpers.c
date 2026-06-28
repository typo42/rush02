/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion_helpers.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_hundred_word(char *s, char *c, t_entry *entries,
		ssize_t n_entries)
{
	char	*word;

	convert_ones(c, entries, n_entries);
	word = lookup("100", entries, n_entries);
	if (!word)
	{
		ft_putstr(DICT_ERROR);
		free(c);
		return (-1);
	}
	write(1, " ", 1);
	write(1, word, ft_strlen(word));
	if (s[1] != '0' || s[2] != '0')
		write(1, " ", 1);
	return (0);
}

int	has_remaining_digits(char *start)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if (start[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	print_scale_word(int len, int remaining_nz,
		t_entry *entries, ssize_t n_entries)
{
	char	*k;

	write(1, " ", 1);
	k = make_key(len);
	put_word(k, entries, n_entries);
	free(k);
	if (remaining_nz)
		write(1, " ", 1);
}

int	convert_remaining(char *number, int triplet_nz,
		t_entry *entries, ssize_t n_entries)
{
	char	*start;
	char	*new;
	int		len;
	int		i;
	int		remaining_nz;

	len = ft_strlen(number);
	new = malloc(len - 2);
	start = new;
	i = 3;
	while (number[i])
		*new++ = number[i++];
	*new = '\0';
	remaining_nz = has_remaining_digits(start);
	if (triplet_nz)
		print_scale_word(len, remaining_nz, entries, n_entries);
	if (remaining_nz)
		magic(start, entries, n_entries);
	free(start);
	return (0);
}
