/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:44:20 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/27 16:13:30 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_rec_pow(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_rec_pow(nb, power - 1));
}

int	count_p_1000(int nb)
{
	int	group_count;

	group_count = 0;
	while (nb > 0)
	{
		group_count++;
		nb /= 1000;
	}
	return (group_count);
}
