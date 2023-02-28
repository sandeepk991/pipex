/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:31:51 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 13:36:55 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int			index;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char **ft_split(char const *s, char c);

int main(void)
{
  char s[] = "To be, or not to be, that is the question.";
  int count_strings = 0;
  char c[] = ",";
  char *split_strings = ft_split(s, c);
  for (int i = 0; i < count_strings; i++)
    printf("%s\n", split_strings[i]);

   for (int i = 0; i < count_strings; i++)
    free(split_strings[i]);
  free(split_strings);

  return 0;
}*/
