/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:58:30 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 00:55:32 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_data *data) // ekrani temizlemek icin
{
	int i = 0;
	int j = 0;

	while (i < data->height)
	{
		while (j < data->width)
		{
			ft_my_put_pixel(&data->img, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 600)
	{
		while (j < 600)
		{
			ft_my_put_pixel(&data->img2, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 600)
	{
		while (j < 600)
		{
			ft_my_put_pixel(&data->img3, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 600)
	{
		while (j < 600)
		{
			ft_my_put_pixel(&data->img4, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
}

double	deg2rad(int deg)
{
	return (deg * (M_PI / 180));
}
/*duvarlarin baktigi yonlere gore resim ve ya renk koyar draw_wall fonksiyonlarinda*/
void	draw_wall_n(int angle, double distance, t_data *data,
		t_ray_data *ray_data)
{
	int	height;
	int	start;
	int	end;
	int	i;

	(void)ray_data;
	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, 0xff0000); // kirmizi
		i++;
	}
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_FLOOR);
		i++;
	}
}

void	draw_wall_e(int angle, double distance, t_data *data,
		t_ray_data *ray_data)
{
	int	height;
	int	start;
	int	end;
	int	i;

	(void)ray_data;
	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, 0x00ff00); // yesil
		i++;
	}
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_FLOOR);
		i++;
	}
}

void	draw_wall_w(int angle, double distance, t_data *data,
		t_ray_data *ray_data)
{
	int	height;
	int	start;
	int	end;
	int	i;

	(void)ray_data;
	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, 0x0000ff); // mavi
		i++;
	}
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_FLOOR);
		i++;
	}
}

void	draw_wall_s(int angle, double distance, t_data *data,
		t_ray_data *ray_data)
{
	int	height;
	int	start;
	int	end;
	int	i;

	(void)ray_data;
	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, 0xaaaaaa); // acik gri
		i++;
	}
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img3, angle, i, T_FLOOR);
		i++;
	}
}
/*tek renk duvar cizer ilk asama*/
int	draw_wall(int angle, double distance, t_data *data, t_ray_data *ray_data)
{
	int	height;
	int	start;
	int	end;
	int	i;

	(void)ray_data;
	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img2, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img2, angle, i, 0x00ff00);
		i++;
	}
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img2, angle, i, 0x000000);
		i++;
	}
	return (0);
}
/*tek renk ekran*/
int	draw_screen2(t_data *data, t_ray_data *ray_data)
{
	int	i;

	i = 0;
	while (i < 600)
	{
		draw_wall(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2)
					+ ft_pow(ray_data[i].ray_location.y, 2)), data, ray_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win2, data->img2.img, 0, 0);
	return (0);
}
/*renkli ekran*/
int	draw_screen3(t_data *data, t_ray_data *ray_data)
{
	int	i;

	i = 0;
	while (i < 600)
	{
		if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1
			&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_e(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2)
						+ ft_pow(ray_data[i].ray_location.y, 2)), data,
					ray_data);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
				&& ray_data[i].last_location.y
				+ 1 == ray_data[i].wall_location.y)
			draw_wall_n(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2)
						+ ft_pow(ray_data[i].ray_location.y, 2)), data,
					ray_data);
		if (ray_data[i].last_location.x + 1 == ray_data[i].wall_location.x
			&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_w(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2)
						+ ft_pow(ray_data[i].ray_location.y, 2)), data,
					ray_data);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
				&& ray_data[i].last_location.y == ray_data[i].wall_location.y
				+ 1)
			draw_wall_s(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2)
						+ ft_pow(ray_data[i].ray_location.y, 2)), data,
					ray_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win3, data->img3.img, 0, 0);
	return (0);
}


void	render_window(t_data *data)
{
	double		angle;
	t_ray_data	*ray;
	int			i;

	i = GAMEWIDTH;
	angle = data->player.fov;
	ray = (t_ray_data *)malloc(sizeof(t_ray_data) * GAMEWIDTH);
	mlx_clear_window(data->mlx, data->win4);
	clear_img(data);
	draw_outlines(data);
	while (i--)
	{
		ray[i] = calculate_ray(data, angle);
		angle -= data->player.fov / GAMEWIDTH;
	}
	draw_screen2(data, ray);
	draw_screen3(data, ray);
	/*draw_screen4 xpmli ekran*/
	draw_screen4(data, ray);
	data->dist_l = ft_sqrt(ft_pow(ray[0].ray_location.x, 2)
			+ ft_pow(ray[0].ray_location.y, 2));
	data->dist_r = ft_sqrt(ft_pow(ray[GAMEWIDTH - 1].ray_location.x, 2)
			+ ft_pow(ray[GAMEWIDTH - 1].ray_location.y, 2));
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	free(ray);
}

int	error_check(t_data *data, char *path)
{
	int			fd;
	t_control	control;

	fd = open(path, O_RDONLY);
	if (fd < 0 || extension_check(path) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	control = (t_control){read_file(data, fd), check_wall_xpm(data),
		ft_get_map(data, path), ft_set_map(data),
		.player_pos = (data->player.pos.x == 0 && data->player.pos.y == 0)
		* (xpm | map | int_map)};
	if (control.read_file != 0 || control.check_wall != 0
		|| control.get_map != 0 || control.set_map != 0
		|| control.player_pos != 0)
	{
		control = ft_recontrol(control);
		free_func(data, control.check_wall | control.get_map | \
		control.player_pos | control.read_file | control.set_map);
		printf("Error\n");
		return (-1);
	}
	return (0);
}

int	extension_check(char *path)
{
	if (ft_strlen(path) > 4 && path[ft_strlen(path) - 1] == 'b'
		&& path[ft_strlen(path) - 2] == 'u' && path[ft_strlen(path) - 3] == 'c'
		&& path[ft_strlen(path) - 4] == '.')
		return (0);
	return (-1);
}

void	ft_xpm_cleaner(t_data *data)
{
	if (data->map_data.xpm_dir[0])
		free(data->map_data.xpm_dir[0]);
	if (data->map_data.xpm_dir[1])
		free(data->map_data.xpm_dir[1]);
	if (data->map_data.xpm_dir[2])
		free(data->map_data.xpm_dir[2]);
	if (data->map_data.xpm_dir[3])
		free(data->map_data.xpm_dir[3]);
}
