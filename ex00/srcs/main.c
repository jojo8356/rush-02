/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:42:47 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 17:56:36 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	verif_argc(int argc)
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	verif_numbers(t_dict *numbers)
{
	if (!numbers)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		number;
	char	*text;
	t_dict	*numbers;

	verif_argc(argc);
	number = ft_atoi(argv[1]);
	if (argc >= 2 && !str_is_digit(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	numbers = format_all("numbers.dict");
	verif_numbers(numbers);
	text = convert_nb(numbers, number);
	ft_dict_clear(numbers, NULL);
	if (text)
	{
		ft_putstr(text);
		free(text);
	}
	else
	{
		ft_putstr("Error\n");
	}
	return (0);
}
