/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:49:59 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/24 23:54:52 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//yonlerine gore xpmli ekran basma
int	draw_wall_n_img(int angle, double distance, t_data *data,
		t_ray_data ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.x
						- floor(ray_data.for_wall.x)) * 64), ((i - start) * 64)
				/ height, 0);
		ft_my_put_pixel(&data->img4, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_e_img(int angle, double distance, t_data *data,
		t_ray_data ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.y
						- floor(ray_data.for_wall.y)) * 64), ((i - start) * 64)
				/ height, 1);
		ft_my_put_pixel(&data->img4, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_w_img(int angle, double distance, t_data *data,
		t_ray_data ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.y
						- floor(ray_data.for_wall.y)) * 64), ((i - start) * 64)
				/ height, 2);
		ft_my_put_pixel(&data->img4, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_wall_s_img(int angle, double distance, t_data *data,
		t_ray_data ray_data)
{
	int				height;
	int				start;
	int				end;
	int				i;
	unsigned int	clr;

	distance = distance * cos(deg2rad((((double)angle * 0.1) - (data->player.fov
						/ 2))));
	height = (int)(50000 / distance);
	start = (600 - height) / 2;
	end = (600 + height) / 2;
	i = 0;
	i = draw_ceiling(angle, i, start, data);
	while (i < end)
	{
		if (i >= 600)
			break ;
		clr = ft_my_get_pixel(data, ((ray_data.for_wall.x
						- floor(ray_data.for_wall.x)) * 64), ((i - start) * 64)
				/ height, 3);
		ft_my_put_pixel(&data->img4, angle, i, clr);
		i++;
	}
	i = draw_floor(angle, i, data);
	return (0);
}

int	draw_walls(t_data *data, t_ray_data *ray_data, double distance)
{
	t_llocation	last_location;
	t_llocation	wall_location;

	last_location = ray_data[data->dray].last_location;
	wall_location = ray_data[data->dray].wall_location;
	if (last_location.x == wall_location.x + 1 && last_location.y
		== wall_location.y)
		return (draw_wall_e_img(data->dray, distance,
				data, ray_data[data->dray]));
	else if (last_location.x == wall_location.x
		&& last_location.y + 1 == wall_location.y)
		return (draw_wall_n_img(data->dray, distance, data,
				ray_data[data->dray]));
	else if (last_location.x
		+ 1 == wall_location.x
		&& last_location.y == wall_location.y)
		return (draw_wall_w_img(data->dray, distance, data,
				ray_data[data->dray]));
	else if (last_location.x == wall_location.x
		&& last_location.y == wall_location.y + 1)
		return (draw_wall_s_img(data->dray, distance,
				data, ray_data[data->dray]));
	return (1);
}
