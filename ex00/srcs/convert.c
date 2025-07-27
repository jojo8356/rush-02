/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:18:46 by johan             #+#    #+#             */
/*   Updated: 2025/07/27 10:50:11 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	convert_nb_less_100(int nb, char **result, t_dict *numbers, int *i)
{
	char	*tmp2;

	if (nb > 0)
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
				tmp2 = get_value(numbers, nb % 10);
				result[*i] = ft_strcat_malloc(result[*i], tmp2);
			}
			(*i)++;
		}
	}
}

void	convert_nb_less_1000(int nb, char **result, t_dict *numbers, int *i)
{
	char	*tmp;

	if (nb == 0)
		return ;
	if (nb >= 100)
	{
		tmp = get_value(numbers, nb / 100);
		tmp = ft_strcat_malloc(tmp, " hundred");
		nb = nb % 100;
		if (nb > 0)
			tmp = ft_strcat_malloc(tmp, " and");
		convert_nb_less_100(nb, result, numbers, i);
		result[*i] = tmp;
		(*i)++;
	}
	else
		convert_nb_less_100(nb, result, numbers, i);
}

void	main_loop(int nb, int *i, t_dict *numbers, char **result)
{
	int	current_group;
	int	power;

	power = 0;
	current_group = 0;
	while (nb > 0)
	{
		current_group = nb % 1000;
		if (current_group > 0)
		{
			if (power > 0)
			{
				result[*i] = get_value(numbers, (int)ft_rec_pow(1000, power));
				result[*i] = ft_strcat_malloc(result[*i], ",");
				(*i)++;
			}
			convert_nb_less_1000(current_group, result, numbers, i);
		}
		nb /= 1000;
		power++;
	}
}

char	*convert_nb(t_dict *numbers, int nb)
{
	char	**result;
	char	**final_result;
	char	*final_string;
	int		i;
	int		j;

	j = 0;
	if (nb == 0)
		return (get_value(numbers, 0));
	result = malloc(count_p_1000(nb) * 2 * sizeof(char *));
	i = 0;
	main_loop(nb, &i, numbers, result);
	final_result = malloc(i * sizeof(char *));
	while (j < i)
	{
		final_result[j] = result[i - 1 - j];
		j++;
	}
	final_string = ft_strjoin(i, final_result, " ");
	free(result);
	free(final_result);
	return (final_string);
}
