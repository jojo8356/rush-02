/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:55:02 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/24 17:31:45 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
    printf("Test 1 : %d (attendu: 5)\n", ft_strlen("hello"));
    printf("Test 2 : %d (attendu: 0)\n", ft_strlen(""));
    printf("%d (attendu: 13)\n", ft_strlen("C programming"));
    printf("%d (attendu: 10)\n", ft_strlen("1234567890"));
    printf("%d (attendu: 2)\n", ft_strlen("\n\t"));
    printf("Test 6 : \"a\" ➜ %d (attendu: 1)\n", ft_strlen("a"));

    return 0;
}*/
