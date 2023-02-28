/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:16:15 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 13:38:57 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && *little != '\0' && len-- >= i)
	{
		if (*big == *little && ft_strncmp(big, little, i) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
/*#include<bsd/string.h>
int main (void)
{
	const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = ft_strnstr(largestring, smallstring, 11);
	   printf("given string is : %s", ptr);
	   return (0);
}*/
