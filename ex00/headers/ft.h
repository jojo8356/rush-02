/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:43 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 16:14:22 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_dict
{
	struct s_dict	*next;
	long long int	key;
	char			*value;
}	t_dict;

char	**ft_split(char *str, char *charset, int *len);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_dict_push_back(t_dict **begin_dict, long long int key, void *value);
void	print_dict(t_dict *dict);
t_dict	*format_all(const char *filename);
char	*get_content_file(const char *filename);
int		ft_atoi(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*get_value(t_dict *begin_dict, long long key);
char	*ft_strcat_malloc(char *a, char *b);
t_dict	*ft_create_elem(long long key, void *value);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*convert_nb(t_dict *numbers, int nb);
int		count_p_1000(int nb);
int		ft_rec_pow(int nb, int power);
int		str_is_digit(char *str);
int		is_digit(char str);