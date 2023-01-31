/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:15:37 by skaur             #+#    #+#             */
/*   Updated: 2023/01/27 13:09:08 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>

int main(int ac, char *av[])
{
    int fd1;
    int fd2;
    char c;

    if (ac == 3)
    {
        fd1 = open(av[1], O_RDONLY);
        fd2 = open(av[2], O_RDWR);
        while (read(fd1, &c, 1) > 0)
        {
            write(fd2, &c, 1);
            //printf("number of lines : %i", )
        }
        close(fd1);
        close(fd2);
    }
    else
        printf("error");
    return (0);
}
