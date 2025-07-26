/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:16:37 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:50:45 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_dict {
    char *key;
    char *value;
    struct s_dict *next;
} t_dict;

char *ft_strtrim(char *s);
char *ft_strdup(const char *s);
char *ft_strcat_malloc(char *a, char *b);
t_dict *parse_dict(char *path);
void free_dict(t_dict *dict);
int convert_number(char *num, t_dict *dict);
int	ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
int	ft_strcmp(const char *s1, const char *s2);