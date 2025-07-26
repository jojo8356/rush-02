/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:38:43 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:39:10 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	convert_number(char *num, t_dict *dict)
{
	while (dict)
	{
		if (!ft_strcmp(dict->key, num))
		{
			ft_putstr(dict->value);
			write(1, "\n", 1);
			return (1);
		}
		dict = dict->next;
	}
	return (0);
}