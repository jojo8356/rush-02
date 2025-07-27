/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:44:20 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 16:09:47 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	is_digit(char str)
{
	return ('0' <= str && str <= '9');
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}