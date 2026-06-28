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

int	convert_ones(char *s, t_entry *entries, ssize_t size)
{
	if (s[1] != '\0')
		return (0);
	if (s[0] == '0')
		return (0);
	return (put_word(s, entries, size));
}

int	convert_tens(char *s, t_entry *entries, ssize_t size)
{
	char	*c;
	int		ret;

	if (s[2] != '\0')
		return (0);
	c = make_word(s[1], '\0', 1);
	if (c == NULL)
		return (-1);
	if (s[0] == '0')
		ret = convert_ones(c, entries, size);
	else if (s[0] == '1')
		ret = put_word(s, entries, size);
	else
		ret = convert_full_tens(s, c, entries, size);
	free(c);
	return (ret);
}

int	convert_hundreds(char *s, t_entry *entries, ssize_t size)
{
	char	*last_two;
	int		ret;

	if (s[3] != '\0')
		return (0);
	if (s[0] != '0')
	{
		ret = print_hundred_prefix(s, entries, size);
		if (ret == -1)
			return (-1);
	}
	last_two = make_word(s[1], s[2], 2);
	if (last_two == NULL)
		return (-1);
	ret = convert_tens(last_two, entries, size);
	free(last_two);
	return (ret);
}

int	magic(char *number, t_entry *entries, ssize_t size)
{
	if (ft_strlen(number) > 39)
	{
		ft_putstr(ERROR);
		return (-1);
	}
	return (convert_groups(number, entries, size));
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
