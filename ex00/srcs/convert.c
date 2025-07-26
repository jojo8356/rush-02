#include "ft.h"
#include <stdio.h>

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
	if (nb == 0)
		return ;

	if (nb >= 100)
	{
		result[*i] = get_value(numbers, nb / 100);
		result[*i] = ft_strcat_malloc(result[*i], " hundred");
		nb = nb % 100;
		if (nb > 0)
		{
			if (nb <= 20)
				result[*i] = ft_strcat_malloc(result[*i], get_value(numbers, nb));
			else
			{
				result[*i] = ft_strcat_malloc(result[*i], get_value(numbers, nb / 10));
				result[*i] = ft_strcat_malloc(result[*i], "-");
				result[*i] = ft_strcat_malloc(result[*i], get_value(numbers, nb % 10));
			}
		}
	}
}

char *convert_nb(t_dict *numbers, int nb)
{
    char **result;
    int len_nb;
    int i;
	int p;

    len_nb = len_int(nb);
    result = malloc(len_nb * sizeof(char *));
    i = 0;
	p = 0;
    while (nb > 0)
    {
		printf("%d", nb);
		convert_nb_less_1000(nb / 1000, result, numbers, &i);
		if (p > 0)
		{
			result[i] = get_value(numbers, (int)ft_recursive_power(10, p*3));
			i++;
		}
        nb /= 1000;
		p++;
    }
    return (ft_strjoin(i, result, " "));
}