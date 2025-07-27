/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:40:15 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 17:54:31 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_dict	*ft_create_elem(long long key, void *value)
{
	t_dict	*element;

	element = malloc(sizeof(t_dict));
	if (element == NULL)
		return (NULL);
	element->key = (long long int)key;
	element->value = value;
	element->next = NULL;
	return (element);
}

void	ft_dict_push_back(t_dict **begin_dict, long long int key, void *value)
{
	t_dict	*element;
	t_dict	*current;

	element = ft_create_elem(key, value);
	if (!element)
		return ;
	if (*begin_dict == NULL)
	{
		*begin_dict = element;
		return ;
	}
	current = *begin_dict;
	while (current->next != NULL)
		current = current->next;
	current->next = element;
}
