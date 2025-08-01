/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:40:15 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 17:55:42 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_dict_clear(t_dict *begin_dict, void (*free_fct)())
{
	t_dict	*current;
	t_dict	*next;

	current = begin_dict;
	while (current)
	{
		next = current->next;
		if (free_fct)
		{
			free_fct((long long int)current->key);
			free_fct(current->value);
		}
		free(current);
		current = next;
	}
}

char	*get_value(t_dict *begin_dict, long long int key)
{
	t_dict	*current;

	current = begin_dict;
	while (current->next != NULL)
	{
		if (current->key == key)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
