/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:40:39 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 10:56:58 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

ssize_t	count_bytes(const char *filename)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;
	ssize_t	total;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	total = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read <= 0)
			break ;
		total += bytes_read;
	}
	close(fd);
	if (bytes_read < 0)
		return (-1);
	return (total);
}

char	*get_content_file(const char *filename)
{
	int		size;
	char	*result;
	int		i;
	char	buffer;
	int		fd;

	i = 0;
	size = count_bytes(filename);
	result = malloc(size * sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (read(fd, &buffer, 1) != 0)
	{
		result[i] = buffer;
		i++;
	}
	return (result);
}

char	**get_elements_by_line(char *line)
{
	int	len_elements;

	len_elements = 2;
	return (ft_split(line, ": ", &len_elements));
}

char	**get_lines(const char *filename)
{
	char	*content;

	content = get_content_file(filename);
	return (ft_split(content, "\n", &len_line));
}

t_dict	*format_all(const char *filename)
{
	int		i;
	char	**lines;
	int		len_line;
	char	**elements;
	t_dict	*result;

	lines = get_lines(filename);
	i = 0;
	while (i < len_line - 1)
	{
		elements = get_elements_by_line(lines[i]);
		if (i == 0)
			result = ft_create_elem((int)ft_atoi(elements[0]), elements[1]);
		else
			ft_dict_push_back(&result, (int)ft_atoi(elements[0]), elements[1]);
		i++;
	}
	return (result);
}
