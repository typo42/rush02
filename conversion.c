/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 14:31:34 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:24:22 by fqussay         ###   ########.fr        */
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
	char	*word;
	int		ret;

	c = malloc(2);
	c[0] = s[1];
	c[1] = '\0';
	if (s[2] != '\0')
	{
		free(c);
		return (0);
	}
	if (s[0] == '0')
	{
		ret = convert_ones(c, entries, size);
		free(c);
		return (ret);
	}
	if (s[0] == '1')
	{
		free(c);
		return (put_word(s, entries, size));
	}
	word = malloc(3);
	word[0] = s[0];
	word[1] = '0';
	word[2] = '\0';
	put_word(word, entries, size);
	free(word);
	if (s[1] != '0')
	{
		write(1, " ", 1);
		ret = convert_ones(c, entries, size);
		free(c);
		return (ret);
	}
	free(c);
	return (0);
}

int	convert_hundreds(char *s, t_entry *entries, ssize_t size)
{
	char	*c;
	char	*word;
	char	*last_two;

	c = malloc(2);
	c[0] = s[0];
	c[1] = '\0';
	if (s[3] != '\0')
	{
		free(c);
		return (0);
	}
	if (s[0] != '0')
	{
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
	}
	free(c);
	last_two = malloc(3);
	last_two[0] = s[1];
	last_two[1] = s[2];
	last_two[2] = '\0';
	convert_tens(last_two, entries, size);
	free(last_two);
	return (0);
}

int	magic(char *number, t_entry *entries, ssize_t size)
{
	char	*triplet;
	char	*new;
	char	*start;
	int		i;
	int		len;
	int		triplet_nz;
	int		remaining_nz;
	char	*k;

	len = ft_strlen(number);
	if (len > 39)
	{
		ft_putstr(ERROR);
		return (-1);
	}
	triplet = malloc(4);
	triplet[0] = number[0];
	triplet[1] = number[1];
	triplet[2] = number[2];
	triplet[3] = '\0';
	triplet_nz = (triplet[0] != '0' || triplet[1] != '0' || triplet[2] != '0');
	if (triplet_nz)
		convert_hundreds(triplet, entries, size);
	free(triplet);
	if (len > 3)
	{
		new = malloc(len - 2);
		start = new;
		i = 3;
		while (number[i])
			*new++ = number[i++];
		*new = '\0';
		remaining_nz = 0;
		i = 0;
		while (start[i])
		{
			if (start[i] != '0')
			{
				remaining_nz = 1;
				break ;
			}
			i++;
		}
		if (triplet_nz)
		{
			write(1, " ", 1);
			k = key_create(len);
			put_word(k, entries, size);
			free(k);
			if (remaining_nz)
				write(1, " ", 1);
		}
		if (remaining_nz)
			magic(start, entries, size);
		free(start);
	}
	return (0);
}

char	*key_create(int len)
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
