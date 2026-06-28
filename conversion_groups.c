/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   conversion_groups.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/28 13:00:00 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 13:00:00 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_scale(int len, t_entry *entries, ssize_t size)
{
	char	*k;
	int		ret;

	k = make_key(len);
	if (k == NULL)
		return (-1);
	ret = put_word(k, entries, size);
	free(k);
	return (ret);
}

int	print_scale_part(int len, int remaining_nz,
		t_entry *entries, ssize_t size)
{
	int	ret;

	write(1, " ", 1);
	ret = print_scale(len, entries, size);
	if (ret == -1)
		return (-1);
	if (remaining_nz)
		write(1, " ", 1);
	return (0);
}

int	convert_rest(char *number, int triplet_nz,
		t_entry *entries, ssize_t size)
{
	char	*rest;
	int		remaining_nz;
	int		ret;

	rest = next_group(number);
	if (rest == NULL)
		return (-1);
	remaining_nz = has_nonzero(rest);
	ret = 0;
	if (triplet_nz)
		ret = print_scale_part(ft_strlen(number), remaining_nz, entries, size);
	if (ret == 0 && remaining_nz)
		ret = magic(rest, entries, size);
	free(rest);
	return (ret);
}

int	convert_groups(char *number, t_entry *entries, ssize_t size)
{
	char	*triplet;
	int		triplet_nz;
	int		ret;
	int		len;

	len = ft_strlen(number);
	triplet = make_triplet(number);
	if (triplet == NULL)
		return (-1);
	triplet_nz = has_nonzero(triplet);
	ret = 0;
	if (triplet_nz)
		ret = convert_hundreds(triplet, entries, size);
	free(triplet);
	if (ret == -1)
		return (-1);
	if (len > 3)
		return (convert_rest(number, triplet_nz, entries, size));
	return (0);
}
