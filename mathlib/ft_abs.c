/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:34:01 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 00:34:02 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

int	ft_abs(int var)
{
	if (var >= 0)
	{
		return (var);
	}
	else
	{
		return (-var);
	}
}
