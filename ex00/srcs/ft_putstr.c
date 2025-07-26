/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:44:47 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/18 09:27:20 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*
#include <stdio.h>

int main(void)
{
    ft_putstr("Hello World");
    ft_putchar('\n');

    ft_putstr("42");
    ft_putchar('\n');

    return 0;
}*/
