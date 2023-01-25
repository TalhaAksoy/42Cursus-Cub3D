/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:31:58 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 09:44:37 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_height(char *path)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		ret;

	fd = open(path, O_RDONLY);
	ret = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_is_space(line);
		if (*tmp == '0' || *tmp == '1')
			ret++;
	}
	return (ret);
}

int	put_map(t_data *data, char **lines)
{
	int	i;

	i = 0;
	while (data->map_data.map_start + i <= data->map_data.map_end)
	{
		data->map_data.map[i] = ft_strdup(lines[data->map_data.map_start + i]);
		i++;
	}
	array_cleaner((void **)lines);
	if (check_wall(data) == -1)
		return (-1);
	return (0);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (left_wall(data) == -1 || top_wall(data) == -1 || bottom_wall(data)
		== -1)
		return (-1);
	while (data->map_data.map[++i])
	{
		while (data->map_data.map[i][++j])
		{
			if (data->map_data.map[i][j] == '0'
				|| data->map_data.map[i][j] == 'N'
				|| data->map_data.map[i][j] == 'S'
				|| data->map_data.map[i][j] == 'E'
				|| data->map_data.map[i][j] == 'W')
			{
				if (check_all_way(data, i, j) == -1)
					return (-1);
			}
		}
		j = 0;
	}
	return (0);
}

/* 0 ve yon karakterlerinin etrafinin 32 olup olmadigini full kontrol eder*/
int	check_all_way(t_data *data, int i, int j)
{
	if (data->map_data.map[i - 1][j] == 32 || (data->map_data.map[i - 1][j] >= 9
			&& data->map_data.map[i - 1][j] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j] == 32 || (data->map_data.map[i + 1][j] >= 9
			&& data->map_data.map[i + 1][j] <= 13))
		return (-1);
	if (data->map_data.map[i][j - 1] == 32 || (data->map_data.map[i][j - 1] >= 9
			&& data->map_data.map[i][j - 1] <= 13))
		return (-1);
	if (data->map_data.map[i][j + 1] == 32 || (data->map_data.map[i][j + 1] >= 9
			&& data->map_data.map[i][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j + 1] == 32 || (data->map_data.map[i + 1][j
			+ 1] >= 9 && data->map_data.map[i + 1][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i - 1][j - 1] == 32 || (data->map_data.map[i - 1][j
			- 1] >= 9 && data->map_data.map[i - 1][j - 1] <= 13))
		return (-1);
	if (data->map_data.map[i - 1][j + 1] == 32 || (data->map_data.map[i - 1][j
			+ 1] >= 9 && data->map_data.map[i - 1][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j - 1] == 32 || (data->map_data.map[i + 1][j
			- 1] >= 9 && data->map_data.map[i + 1][j - 1] <= 13))
		return (-1);
	return (0);
}

int	ft_count_line(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		++line_count;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!line_count)
		return (-1);
	return (line_count);
}
