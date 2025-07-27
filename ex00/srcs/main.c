/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:42:47 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 10:44:08 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		number;
	char	*text;
	t_dict	*numbers;

	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	number = ft_atoi(argv[1]);
	numbers = format_all("numbers.dict");
	if (!numbers)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	text = convert_nb(numbers, number);
	if (text)
	{
		ft_putstr(text);
		free(text);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
