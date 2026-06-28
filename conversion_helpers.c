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

int	free_and_put(char *c, char *s, t_entry *entries, ssize_t size)
{
	free(c);
	return (put_word(s, entries, size));
}

int	finish_tens(char *s, char *c, t_entry *entries, ssize_t size)
{
	char	*word;
	int		ret;

	word = make_word(s[0], '0', 2);
	put_word(word, entries, size);
	free(word);
	if (s[1] != '0')
	{
		write(1, " ", 1);
		ret = convert_ones(c, entries, size);
		return (ret);
	}
	return (0);
}

int	print_hundred_word(char *s, char *c, t_entry *entries, ssize_t size)
{
	char	*word;

	convert_ones(c, entries, size);
	word = lookup("100", entries, size);
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
		t_entry *entries, ssize_t size)
{
	char	*k;

	write(1, " ", 1);
	k = make_key(len);
	put_word(k, entries, size);
	free(k);
	if (remaining_nz)
		write(1, " ", 1);
}
