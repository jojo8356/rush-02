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

int	ft_dict_size(t_dict *begin_dict)
{
	if (begin_dict == NULL)
		return (0);
	return (1 + ft_dict_size(begin_dict->next));
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

void	ft_dict_clear(t_dict *begin_dict, void (*free_fct)())
{
	t_dict	*current;
	t_dict	*next;

	current = begin_dict;
	while (current)
	{
		next = current->next;
		if (free_fct)
			free_fct((long long int)current->key);
            free_fct(current->value);
		free(current);
		current = next;
	}
}

void print_dict(t_dict *dict)
{
	while (dict)
	{
		ft_putstr("key: ");
		ft_putstr((char *)dict->key);
		ft_putstr(", value: ");
		ft_putstr((char *)dict->value);
		ft_putstr(" -> ");
		dict = dict->next;
	}
	ft_putstr("NULL\n");
}

char *get_value(t_dict *begin_dict, long long int key)
{
	t_dict	*current;
	current = begin_dict;
	while (current->next != NULL)
	{
		if (current->key == key)
			return (current->value);
		current = current->next;
	}
	return NULL;
}
