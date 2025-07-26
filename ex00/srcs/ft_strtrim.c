/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:34:42 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:34:47 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_strtrim(char *s)
{
	int		start = 0;
	int		end;
	char	*res;
	int		i = 0;

	if (!s)
		return (NULL);
	while (s[start] && is_space(s[start]))
		start++;
	end = start;
	while (s[end])
		end++;
	end--;
	while (end > start && is_space(s[end]))
		end--;
	res = malloc(end - start + 2);
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
