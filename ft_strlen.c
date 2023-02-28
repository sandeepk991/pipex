/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:08:53 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 13:38:04 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}		
	return (len);
}
/*int main(void)
{
    char str[]="";
    // Using %zu format specifier to print size_t
    printf("Length of string a = %zu \n", strlen(str));
    return 0;
}*/
