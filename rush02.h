/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rush02.h                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: fqussay <fqussay@student.42abudhabi.ae>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/27 12:47:42 by fqussay          #+#    #+#              */
/*   Updated: 2026/06/28 00:05:27 by fqussay         ###   ########.fr        */
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

int		put_word(char *s, t_entry *entries, ssize_t size);
int		arg_valid(char *arg);
int		convert_ones(char *c, t_entry *entries, ssize_t size);
int		convert_tens(char *s, t_entry *entries, ssize_t size);
int		convert_hundreds(char *s, t_entry *entries, ssize_t size);
int		count_entries(char *dict);
int		magic(char *number, t_entry *entries, ssize_t size);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
ssize_t	get_dict_size(char *file);
t_entry	*parse_dict(char *dict, t_entry *entries);
t_entry	*make_entries_array(char *dict);
t_entry	*file_to_array(char *file);
char	*format(char *input);
char	*make_string(int size);
char	*read_dict(char *file);
char	*lookup(char *k, t_entry *entries, ssize_t size);
char	*ft_strdup(char *src);
char	*key_create(int len);

void	ft_putstr(char *str);

#endif
