/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:22:12 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 01:42:38 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*last_trim(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (ft_isprint(str[i]) == 1 && str[i] != 32)
		{
			break ;
		}
		str[i] = 0;
		i--;
	}
	return (str);
}

void	array_cleaner(void **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_null(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->map_data.xpm_dir[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_is_space(char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13 && *s != 10))
	{
		s++;
	}
	return (s);
}

int	longest_line(t_data *data)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (data->map_data.map[i])
	{
		if (ft_strlen(data->map_data.map[i]) > max)
			max = ft_strlen(data->map_data.map[i]);
		i++;
	}
	return (max);
}
