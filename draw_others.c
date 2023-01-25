/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:49:26 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/24 23:49:27 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*tavan rengi*/
int	draw_ceiling(int angle, int i, int start, t_data *data)
{
	while (i < start)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img4, angle, i, data->ceiling_color);
		i++;
	}
	return (i);
}
/*taban rengi*/
int	draw_floor(int angle, int i, t_data *data)
{
	while (i < data->height)
	{
		if (i >= 600)
			break ;
		ft_my_put_pixel(&data->img4, angle, i, data->floor_color);
		i++;
	}
	return (i);
}
/*sol kismi sag kismi baz alarak cizer*/
void	draw_from_right_line(double distance, int i, t_data *data,
		t_ray_data *ray_data)
{
	if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
		draw_wall_e_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y + 1 == ray_data[i].wall_location.y)
		draw_wall_n_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x + 1 == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
		draw_wall_w_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y + 1)
		draw_wall_s_img(data->dray, distance, data, ray_data[i]);
	else if (i < 600)
		draw_from_right_line(distance, i + 1, data, ray_data);
}
/*yukaridakinin tam tersi*/
void	draw_from_left_line(double distance, int i, t_data *data,
		t_ray_data *ray_data)
{
	if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
		draw_wall_e_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y + 1 == ray_data[i].wall_location.y)
		draw_wall_n_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x + 1 == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y)
		draw_wall_w_img(data->dray, distance, data, ray_data[i]);
	else if (ray_data[i].last_location.x == ray_data[i].wall_location.x
		&& ray_data[i].last_location.y == ray_data[i].wall_location.y + 1)
		draw_wall_s_img(data->dray, distance, data, ray_data[i]);
	else if (i > 0)
		draw_from_left_line(distance, i - 1, data, ray_data);
}

int	draw_screen4(t_data *data, t_ray_data *ray_data)
{
	double		distance;

	data->dray = 0;
	while (data->dray < 600)
	{
		distance = ft_sqrt(ft_pow(ray_data[data->dray].ray_location.x, 2)
				+ ft_pow(ray_data[data->dray].ray_location.y, 2));
		if (!draw_walls(data, ray_data, distance))
			;
		else if (data->dray < 300)
			draw_from_right_line(distance, data->dray + 1, data, ray_data);
		else if (data->dray >= 300)
			draw_from_left_line(distance, data->dray - 1, data, ray_data);
		data->dray++;
	}
	mlx_put_image_to_window(data->mlx, data->win4, data->img4.img, 0, 0);
	return (0);
}
