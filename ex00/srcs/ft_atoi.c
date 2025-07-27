/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:45:59 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 17:57:27 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_space(char str)
{
	return ((9 <= str && str <= 13) || str == ' ');
}

int	count_less(char *str, int *i)
{
	int	less;

	less = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			less *= -1;
		(*i)++;
	}
	return (less);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	less;

	i = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	less = count_less(str, &i);
	if (!is_digit(str[i]))
		return (0);
	while (is_digit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * less);
}
