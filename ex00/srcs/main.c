/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johan <johan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 07:26:03 by johan             #+#    #+#             */
/*   Updated: 2025/07/26 07:26:03 by johan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// Erreur + fin
void	put_error(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

// MAIN
int main(int ac, char **av) {
    char *dict_path = "numbers.dict";
    char *num_str;
    t_dict *dict;

    if (ac == 2)
        num_str = av[1];
    else if (ac == 3)
        dict_path = av[1], num_str = av[2];
    else {
        put_error("Error");
        return (1);
    }
    // Validité du nombre
    int i = 0;
    if (!num_str || num_str[0] == '\0')
        return put_error("Error"), 1;
    while (num_str[i]) {
        if (num_str[i] < '0' || num_str[i] > '9')
            return put_error("Error"), 1;
        i++;
    }
    // Parse dictionnaire
    dict = parse_dict(dict_path);
    if (!dict)
        return put_error("Dict Error"), 1;

    if (!convert_number(num_str, dict))
        return put_error("Dict Error"), free_dict(dict), 1;

    free_dict(dict);
    return (0);
}
