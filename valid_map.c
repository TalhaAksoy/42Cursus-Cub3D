/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:31:38 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 01:43:09 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	top_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[0][i])
	{
		if (data->map_data.map[0][i] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	bottom_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[array_len(data->map_data.map) - 1][i])
	{
		if (data->map_data.map[array_len(data->map_data.map) - 1][i] == '0')
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	left_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[i])
	{
		if (data->map_data.map[i][0] == '0')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_multi_map(t_data *data, char **lines)
{
	int		flag;
	int		i;
	char	*tmp;

	i = 0;
	flag = 0;
	while (lines[i])
	{
		tmp = ft_strdup(ft_is_space(lines[i]));
		flag = control(tmp, flag, data, i);
		if (flag == 3)
			return (-1);
		free(tmp);
		i++;
	}
	if (flag == 1)
	{
		data->map_data.map_end = i;
	}
	return (0);
}
