/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion_utils.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert_full_tens(char *s, char *c, t_entry *entries, ssize_t size)
{
	char	*word;
	int		ret;

	word = make_word(s[0], '0', 2);
	if (word == NULL)
		return (-1);
	ret = put_word(word, entries, size);
	free(word);
	if (ret == -1)
		return (-1);
	if (s[1] == '0')
		return (0);
	write(1, " ", 1);
	return (convert_ones(c, entries, size));
}

int	print_hundred_prefix(char *s, t_entry *entries, ssize_t size)
{
	char	*c;
	char	*word;
	int		ret;

	c = make_word(s[0], '\0', 1);
	if (c == NULL)
		return (-1);
	ret = convert_ones(c, entries, size);
	free(c);
	if (ret == -1)
		return (-1);
	word = lookup("100", entries, size);
	if (word == NULL)
	{
		ft_putstr(DICT_ERROR);
		return (-1);
	}
	write(1, " ", 1);
	ft_putstr(word);
	if (s[1] != '0' || s[2] != '0')
		write(1, " ", 1);
	return (0);
}

int	has_nonzero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

char	*next_group(char *number)
{
	char	*rest;
	int		i;

	rest = malloc(ft_strlen(number) - 2);
	if (rest == NULL)
		return (NULL);
	i = 3;
	while (number[i])
	{
		rest[i - 3] = number[i];
		i++;
	}
	rest[i - 3] = '\0';
	return (rest);
}
