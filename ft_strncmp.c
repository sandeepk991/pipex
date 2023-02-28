/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:03 by skaur             #+#    #+#             */
/*   Updated: 2023/02/28 13:38:25 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	temp1;
	unsigned char	temp2;

	while (n-- > 0)
	{
		temp1 = *(unsigned char *)s1++;
		temp2 = *(unsigned char *)s2++;
		if (temp1 != temp2)
			return (temp1 - temp2);
		if (temp1 == '\0')
			return (0);
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
   char str1[15];
   char str2[15];
   int ret;
   int ret1;

   strcpy(str1, "€");
   strcpy(str2, "¿");

   ret1 = strncmp(str1, str2, 4);
   printf("builtin function\n");
   if(ret1 < 0) {
      printf("str1 is less than str2\n");
   } else if(ret1 > 0) {
      printf("str2 is less than str1\n");
   } else {
      printf("str1 is equal to str2\n");
   }

   ret = ft_strncmp(str1, str2, 4);
   printf("\nmy function\n");
   if(ret < 0) {
      printf("str1 is less than str2\n");
   } else if(ret > 0) {
      printf("str2 is less than str1\n");
   } else {
      printf("str1 is equal to str2\n");
   }

   return(0);
}*/
