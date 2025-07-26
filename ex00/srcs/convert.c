/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:18:46 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 18:25:13 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

int len_int(int n)
{
	int len;

	len = 0;
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void convert_nb_less_1000(int nb, char **result, t_dict *numbers, int *i)
{
	char *tmp;
	if (nb == 0)
		return ;

	if (nb >= 100)
	{
		tmp = get_value(numbers, nb / 100);
		tmp = ft_strcat_malloc(tmp, " hundred");
		nb = nb % 100;
		if (nb > 0)
		{
			if (nb <= 20)
			{
				result[*i] = get_value(numbers, nb);
				(*i)++;
			}
			else
			{
				result[*i] = get_value(numbers, (nb / 10) * 10); // Pour avoir 20, 30, 40, etc.
				if (nb % 10 != 0)
				{
					result[*i] = ft_strcat_malloc(result[*i], "-");
					result[*i] = ft_strcat_malloc(result[*i], get_value(numbers, nb % 10));
				}
				(*i)++;
			}
		}
		result[*i] = tmp;
		(*i)++;
	}
	else if (nb > 0)
	{
		if (nb <= 20)
		{
			result[*i] = get_value(numbers, nb);
			(*i)++;
		}
		else
		{
			result[*i] = get_value(numbers, (nb / 10) * 10);
			if (nb % 10 != 0)
			{
				result[*i] = ft_strcat_malloc(result[*i], "-");
				result[*i] = ft_strcat_malloc(result[*i], get_value(numbers, nb % 10));
			}
			(*i)++;
		}
	}
}

char *convert_nb(t_dict *numbers, int nb)
{
	char **result;
	char **final_result;
	int i;
	int temp_nb = nb;
	int group_count = 0;

	if (nb == 0)
		return get_value(numbers, 0);

	// Compter le nombre de groupes de 3 chiffres
	while (temp_nb > 0)
	{
		group_count++;
		temp_nb /= 1000;
	}

	result = malloc(group_count * 2 * sizeof(char *));
	i = 0;
	temp_nb = nb;
	int power = 0;
	
	while (temp_nb > 0)
	{
		int current_group = temp_nb % 1000;
		if (current_group > 0)
		{
			if (power > 0)
			{
				result[i] = get_value(numbers, (int)ft_recursive_power(1000, power));
				i++;
			}
			convert_nb_less_1000(current_group, result, numbers, &i);
		}
		temp_nb /= 1000;
		power++;
	}

	// Inverser l'ordre des éléments
	final_result = malloc(i * sizeof(char *));
	for (int j = 0; j < i; j++)
	{
		final_result[j] = result[i - 1 - j];
	}
	
	char *final_string = ft_strjoin(i, final_result, " ");
	
	free(result);
	free(final_result);
	
	return final_string;
}