/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:28:55 by faydin            #+#    #+#             */
/*   Updated: 2022/01/29 01:06:58 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *a = "ramo";
	int fd = open("deneme.txt",O_CREAT | O_RDWR , 0777);
	ft_putstr_fd(a,fd);
}*/		
