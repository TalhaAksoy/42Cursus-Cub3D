/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:16:40 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 00:17:56 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_direction(t_data *data, int i, int j)
{
	static int	flags;

	if (data->map_data.map[i][j] == 'N')
		data->player.direction = 270;
	else if (data->map_data.map[i][j] == 'W')
		data->player.direction = 180;
	else if (data->map_data.map[i][j] == 'E')
		data->player.direction = 0;
	else if (data->map_data.map[i][j] == 'S')
		data->player.direction = 90;
	else if ((data->map_data.map[i][j] != '0' && data->map_data.map[i][j] != '1'
				&& data->map_data.map[i][j] != 0)
			&& ft_isascii(data->map_data.map[i][j]))
		return (-1);
	if (data->map_data.map[i][j] == 'N' || data->map_data.map[i][j] == 'W'
		|| data->map_data.map[i][j] == 'E' || data->map_data.map[i][j] == 'S')
	{
		flags += 1;
		data->player.pos.x = (double)j + .5;
		data->player.pos.y = (double)i + .5;
		data->map_data.map[i][j] = '0';
	}
	if (flags > 1)
		return (-1);
	return (0);
}

void	init_xpm(t_data *data)
{
	data->xpm[north].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[north], &data->xpm[north].width,
			&data->xpm[north].height);
	data->xpm[north].img_ptr = mlx_get_data_addr(data->xpm[north].img,
			&data->xpm[north].bpp, &data->xpm[north].line_len,
			&data->xpm[north].endian);
	data->xpm[east].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[east], &data->xpm[east].width,
			&data->xpm[east].height);
	data->xpm[east].img_ptr = mlx_get_data_addr(data->xpm[east].img,
			&data->xpm[east].bpp, &data->xpm[east].line_len,
			&data->xpm[east].endian);
	data->xpm[west].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[west], &data->xpm[west].width,
			&data->xpm[west].height);
	data->xpm[west].img_ptr = mlx_get_data_addr(data->xpm[west].img,
			&data->xpm[west].bpp, &data->xpm[west].line_len,
			&data->xpm[west].endian);
	data->xpm[south].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[south], &data->xpm[south].width,
			&data->xpm[south].height);
	data->xpm[south].img_ptr = mlx_get_data_addr(data->xpm[south].img,
			&data->xpm[south].bpp, &data->xpm[south].line_len,
			&data->xpm[south].endian);
}

void	init_var(t_data *data)
{
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.fov = 60;
	data->player.direction = 60;
	data->mlx = mlx_init();
	data->width = MAPWIDTH * 64;
	data->height = MAPHEIGHT * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "UwU");
	data->win4 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT,
			"Real super Lil Dicks");
	data->img4.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img4.addr = mlx_get_data_addr(data->img4.img, &data->img4.bpp,
			&data->img4.line_len, &data->img4.endian);
	ft_bzero(data->xpm, sizeof(t_xpm) * 4);
	ft_bzero(&data->map_data, sizeof(t_mapdata));
	data->ceiling_color = data->map_data.colors[flooor][0] * 0x010000
		+ data->map_data.colors[flooor][1] * 0x0100
		+ data->map_data.colors[flooor][2] * 0x01;
	data->floor_color = data->map_data.colors[ceiling][0] * 0x010000
		+ data->map_data.colors[ceiling][1] * 0x0100
		+ data->map_data.colors[ceiling][2] * 0x01;
}

void	init_color(t_data *data)
{
	data.floor_color = data.map_data.colors[flooor][0] * 0x010000
		+ data.map_data.colors[flooor][1] * 0x0100
		+ data.map_data.colors[flooor][2] * 0x01;
	data.ceiling_color = data.map_data.colors[ceiling][0] * 0x010000
		+ data.map_data.colors[ceiling][1] * 0x0100
		+ data.map_data.colors[ceiling][2] * 0x01;
}
