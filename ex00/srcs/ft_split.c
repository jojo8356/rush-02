/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolsine <jpolsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:16:33 by jpolsine          #+#    #+#             */
/*   Updated: 2025/07/26 09:55:07 by jpolsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset, int *len)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	*len = (count_words(str, charset) + 1);
	result = malloc(sizeof(char *) * (*len));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], charset))
			i++;
		if (i > start)
			result[j++] = word_dup(str, start, i);
	}
	result[j] = NULL;
	return (result);
}

/*
#include <stdio.h>

void print_split(char **split)
{
	int i;

	i = 0;
	while (split && split[i])
	{
		printf("split[%d] = %s\n", i, split[i]);
		i++;
	}
	printf("\n");
}


int main(void)
{
	char **result;

	result = ft_split("hello+world+test", "+");
	print_split(result);

	result = ft_split("42-school-is-cool", "-");
	print_split(result);

	result = ft_split("no_delimiter", ",");
	print_split(result);

	result = ft_split("", "+");
	print_split(result);

	return 0;
}
*/
