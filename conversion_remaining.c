/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion_remaining.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*copy_remaining_number(char *number, int len)
{
	char	*new;
	char	*start;
	int		i;

	new = malloc(len - 2);
	start = new;
	i = 3;
	while (number[i])
		*new++ = number[i++];
	*new = '\0';
	return (start);
}

int	convert_remaining(char *number, int triplet_nz,
		t_entry *entries, ssize_t size)
{
	char	*start;
	int		len;
	int		remaining_nz;

	len = ft_strlen(number);
	start = copy_remaining_number(number, len);
	remaining_nz = has_remaining_digits(start);
	if (triplet_nz)
		print_scale_word(len, remaining_nz, entries, size);
	if (remaining_nz)
		magic(start, entries, size);
	free(start);
	return (0);
}
