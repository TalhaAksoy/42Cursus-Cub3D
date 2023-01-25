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

double	deg2rad(int deg)
{
	return (deg * (M_PI / 180));
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
	while (i--)
	{
		ray[i] = calculate_ray(data, angle);
		angle -= data->player.fov / GAMEWIDTH;
	}
	draw_screen4(data, ray);
	data->dist_l = ft_sqrt(ft_pow(ray[0].ray_location.x, 2)
			+ ft_pow(ray[0].ray_location.y, 2));
	data->dist_r = ft_sqrt(ft_pow(ray[GAMEWIDTH - 1].ray_location.x, 2)
			+ ft_pow(ray[GAMEWIDTH - 1].ray_location.y, 2));
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
	printf("%d, %d, %d, %d, %d\n", control.check_wall, control.get_map,  control.player_pos, control.read_file, control.set_map);
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
