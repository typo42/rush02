/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rush02.h                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: giarovoi <8361011@gmail.com>              #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 12:47:42 by giarovoi         #+#    #+#              */
/*   Updated: 2026/06/28 12:35:54 by giarovoi        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 128
# define DICT_ERROR "Dict Error\n"
# define ERROR "Error\n"

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

int			arg_valid(char *arg);
void		free_dict(t_entry *entries, ssize_t n);
void		set_file_and_number(int argc, char **argv, char **file,
				char **number);
int			print_zero(t_entry *entries, ssize_t n_entries);
int			print_nonzero(char *file, char *number, ssize_t n_entries);
int			run_conversion(char *file, char *number);
char		*format(char *input);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
char		*make_string(int size);
int			put_word(char *s, t_entry *entries, ssize_t size);
int			free_and_put(char *c, char *s, t_entry *entries, ssize_t size);
int			finish_tens(char *s, char *c, t_entry *entries, ssize_t size);
int			print_hundred_word(char *s, char *c, t_entry *entries,
				ssize_t size);
int			convert_ones(char *c, t_entry *entries, ssize_t size);
int			convert_tens(char *s, t_entry *entries, ssize_t size);
int			convert_hundreds(char *s, t_entry *entries, ssize_t size);
int			has_remaining_digits(char *start);
void		print_scale_word(int len, int remaining_nz, t_entry *entries,
				ssize_t size);
char		*copy_remaining_number(char *number, int len);
int			convert_remaining(char *number, int triplet_nz, t_entry *entries,
				ssize_t size);
int			magic(char *number, t_entry *entries, ssize_t size);
char		*make_key(int len);
ssize_t		get_dict_size(char *file);
ssize_t		read_dict_size(int numbers);
int			count_entries(char *dict);
t_entry		*parse_dict(char *dict, t_entry *entries);
t_entry		parse_entry(char *dict);
t_entry		*make_entries_array(char *dict);
char		*read_dict(char *file);
int			get_key_len(char *dict);
char		*skip_to_value(char *dict);
int			get_value_len(char *dict);
char		*copy_key(char *pos, int key_len);
char		*copy_value(char *pos, int value_len);
char		*skip_to_line_end(char *dict);
t_entry		*file_to_array(char *file);
char		*make_word(char first, char second, int len);
char		*make_triplet(char *number);
char		*lookup(char *k, t_entry *entries, ssize_t size);

#endif
