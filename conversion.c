/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 14:31:34 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 12:35:50 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert_ones(char *s, t_entry *entries, ssize_t n_entries)
{
	if (s[1] != '\0')
		return (0);
	if (s[0] == '0')
		return (0);
	return (put_word(s, entries, n_entries));
}

int	convert_tens(char *s, t_entry *entries, ssize_t n_entries)
{
	char	c[2];
	char	*word;
	int		ret;

	c[0] = s[1];
	c[1] = '\0';
	if (s[2] != '\0')
		return (0);
	if (s[0] == '0')
		return (convert_ones(c, entries, n_entries));
	if (s[0] == '1')
		return (put_word(s, entries, n_entries));
	word = make_word(s[0], '0', 2);
	ret = put_word(word, entries, n_entries);
	free(word);
	if (s[1] != '0')
	{
		write(1, " ", 1);
		ret = convert_ones(c, entries, n_entries);
	}
	return (ret);
}

int	convert_hundreds(char *s, t_entry *entries, ssize_t n_entries)
{
	char	*c;
	char	*last_two;

	c = make_word(s[0], '\0', 1);
	if (s[3] != '\0')
	{
		free(c);
		return (0);
	}
	if (s[0] != '0' && print_hundred_word(s, c, entries, n_entries) == -1)
		return (-1);
	free(c);
	last_two = make_word(s[1], s[2], 2);
	convert_tens(last_two, entries, n_entries);
	free(last_two);
	return (0);
}

int	magic(char *number, t_entry *entries, ssize_t n_entries)
{
	char	*triplet;
	int		len;
	int		triplet_nz;

	len = ft_strlen(number);
	if (len > get_longest_key_len(entries, n_entries) + 2)
	{
		ft_putstr(ERROR);
		return (-1);
	}
	triplet = make_triplet(number);
	triplet_nz = (triplet[0] != '0'
			|| triplet[1] != '0' || triplet[2] != '0');
	if (triplet_nz)
		convert_hundreds(triplet, entries, n_entries);
	free(triplet);
	if (len > 3)
		convert_remaining(number, triplet_nz, entries, n_entries);
	return (0);
}

char	*make_key(int len)
{
	char	*output;
	int		zeros;
	int		i;

	output = malloc(len);
	zeros = len - 2;
	output[0] = '1';
	i = 1;
	while (i < zeros)
	{
		output[i] = '0';
		i++;
	}
	output[i] = '\0';
	return (output);
}
