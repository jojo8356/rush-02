/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:39:28 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/26 11:27:21 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_total_length(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i < size - 1)
			total += ft_strlen(sep);
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*result;
	int		i;

	if (size == 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = get_total_length(size, strs, sep);
	result = malloc(total_len + 1);
	if (!result)
		return (0);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	char *words1[] = {"Hello", "world", "!"};
	char *words2[] = {"42", "Nice"};
	char *words3[] = {"Un", "Deux"};
	char *words4[] = {};
	char *sep = " ";

	printf("Test 1 : %s\n", ft_strjoin(3, words1, sep));
	printf("Test 2 : %s\n", ft_strjoin(2, words2, "-"));
	printf("Test 3 : %s\n", ft_strjoin(2, words3, ">>>"));
	printf("Test 4 : %s\n", ft_strjoin(0, words4, "abc"));

	return (0);
}
*/
