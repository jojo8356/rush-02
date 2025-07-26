/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:32:19 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:32:43 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// lis ligne par ligne
char	*read_line(int fd)
{
	char	buf[1];
	char	*line = NULL;
	int		len = 0;
	char	*tmp;

	while (read(fd, buf, 1) == 1)
	{
		if (buf[0] == '\n')
			break;
		tmp = malloc(len + 2);
		if (!tmp)
			return (free(line), NULL);
		for (int i = 0; i < len; i++)
			tmp[i] = line[i];
		tmp[len++] = buf[0];
		tmp[len] = '\0';
		free(line);
		line = tmp;
	}
	return (line);
}

t_dict	*parse_dict(char *path)
{
	int		fd = open(path, O_RDONLY);
	char	*line;
	t_dict	*head = NULL;
	t_dict	*new;
	char	*colon;

	if (fd < 0)
		return (NULL);
	while ((line = read_line(fd)))
	{
		if (!*line) // ligne vide
		{
			free(line);
			continue;
		}
		colon = line;
		while (*colon && *colon != ':')
			colon++;
		if (!*colon)
			return (free(line), free_dict(head), NULL);
		*colon = '\0';
		new = malloc(sizeof(t_dict));
		if (!new)
			return (free(line), free_dict(head), NULL);
		new->key = ft_strtrim(line);
		new->value = ft_strtrim(colon + 1);
		new->next = head;
		head = new;
		free(line);
	}
	close(fd);
	return (head);
}