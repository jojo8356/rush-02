/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:32:12 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:49:27 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcat_malloc(char *a, char *b)
{
	int		len_a;
	int		len_b;
	char	*res;
	int		len;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	len = len_a + len_b + 1;
	res = malloc(len);
	if (!res)
		return (NULL);
	ft_strcat(res, a);
	ft_strcat(res, b);
	res[len - 1] = '\0';
	return (res);
}