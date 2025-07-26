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
	int     size;
	char    *result;
	int     i;
	char	buffer;
	int		fd;

	i = 0;
	size = count_bytes(filename);
	result = malloc(size * sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	while (read(fd, &buffer, 1) != 0)
	{
		result[i] = buffer;
		i++;
	}
	return (result);
}

t_dict *format_all(const char *filename)
{
	char	*content;
	int		i;
	char	**lines;
	int		len_line;
	char	**elements;
	t_dict	*result;
	int len_elements;

	i = 0;
	content = get_content_file(filename);
	lines = ft_split(content, "\n", &len_line);
	while (i < len_line - 1)
	{
		elements = ft_split(lines[i], ": ", &len_elements);
		if (i == 0)
			result = ft_create_elem((int)ft_atoi(elements[0]), elements[1]);
		else
			ft_dict_push_back(&result, (int)ft_atoi(elements[0]), elements[1]);
		i++;
	}

	return (result);
}