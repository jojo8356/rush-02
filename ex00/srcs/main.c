#include "ft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (1);
	}

	// Convertir correctement l'argument en entier
	int number = ft_atoi(argv[1]);

	// Charger le dictionnaire
	t_dict *numbers = format_all("numbers.dict");
	if (!numbers)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}

	// Convertir et afficher le résultat
	char *text = convert_nb(numbers, number);
	if (text)
	{
		ft_putstr(text);
		free(text);
	}
	else
	{
		ft_putstr("Error\n");
	}

	// Libérer le dictionnaire si besoin (si tu as un free_dict)
	// free_dict(numbers);

	return (0);
}