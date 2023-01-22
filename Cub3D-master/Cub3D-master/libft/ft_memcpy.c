/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:34 by faydin            #+#    #+#             */
/*   Updated: 2022/01/25 04:27:43 by eerdem           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *stc, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !stc)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)stc)[i];
		i++;
	}
	return (dst);
}
