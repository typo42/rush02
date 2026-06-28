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
void		set_input(int argc, char **argv, char **file, char **number);
int			load_dict(char *file, t_entry **entries, ssize_t *n_entries);
int			print_number(char *number, t_entry *entries, ssize_t n_entries);
char		*format(char *input);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
char		*make_string(int size);
int			put_word(char *s, t_entry *entries, ssize_t size);
int			convert_ones(char *c, t_entry *entries, ssize_t size);
int			convert_tens(char *s, t_entry *entries, ssize_t size);
int			convert_hundreds(char *s, t_entry *entries, ssize_t size);
int			convert_full_tens(char *s, char *c, t_entry *entries, ssize_t size);
int			print_hundred_prefix(char *s, t_entry *entries, ssize_t size);
int			has_nonzero(char *s);
char		*next_group(char *number);
int			convert_groups(char *number, t_entry *entries, ssize_t size);
int			magic(char *number, t_entry *entries, ssize_t size);
char		*make_key(int len);
ssize_t		get_dict_size(char *file);
int			count_entries(char *dict);
t_entry		*parse_dict(char *dict, t_entry *entries);
t_entry		*make_entries_array(char *dict);
char		*read_dict(char *file);
int			open_dict_file(char *file);
ssize_t		dict_error(int fd);
char		*free_read_dict(char *dict, int fd);
int			key_size(char *line);
char		*value_start(char *line);
int			value_size(char *line);
char		*copy_key(char *line);
char		*copy_value(char *line);
char		*next_line(char *line);
t_entry		make_entry(char *line);
t_entry		*file_to_array(char *file);
char		*make_word(char first, char second, int len);
char		*make_triplet(char *number);
char		*lookup(char *k, t_entry *entries, ssize_t size);

#endif
