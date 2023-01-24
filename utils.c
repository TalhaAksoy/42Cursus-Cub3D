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

void	draw_wall_n_img(int angle, double distance, t_data *data,
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
}

void	draw_wall_e_img(int angle, double distance, t_data *data,
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
}

void	draw_wall_w_img(int angle, double distance, t_data *data,
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
}

void	draw_wall_s_img(int angle, double distance, t_data *data,
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
}

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

int	draw_walls(t_data *data, t_ray_data *ray_data, double distance)
{
	t_llocation	last_location;
	t_llocation	wall_location;

	last_location = ray_data[data->dray].last_location;
	wall_location = ray_data[data->dray].wall_location;
	if (last_location.x == wall_location.x + 1
		&& last_location.y == wall_location.y)
	{	
		draw_wall_e_img(data->dray, distance, data, ray_data[data->dray]);
		return (0);
	}
	else if (last_location.x == wall_location.x
		&& last_location.y + 1 == wall_location.y)
	{	
		draw_wall_n_img(data->dray, distance, data, ray_data[data->dray]);
		return (0);
	}
	else if (last_location.x
		+ 1 == wall_location.x
		&& last_location.y == wall_location.y)
	{	
		draw_wall_w_img(data->dray, distance, data, ray_data[data->dray]);
		return (0);
	}
	else if (last_location.x == wall_location.x
		&& last_location.y == wall_location.y + 1)
	{
		draw_wall_s_img(data->dray, distance, data, ray_data[data->dray]);
		return (0);
	}
	return (1);
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

void	ft_left(t_data *data)
{
	t_vector2	w_check;
	t_vector2	move;

	move = (t_vector2){.y = 0.05 * cos(deg2rad(data->player.direction)),
		.x = 0.05 * sin(deg2rad(data->player.direction))};
	w_check.y = data->player.pos.y - move.y;
	w_check.x = data->player.pos.x + move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1 || data->map_data.int_map[(int)(w_check.y
			+ move.y)][(int)(w_check.x - move.x)] == 1)
		return ;
	data->player.pos.y -= move.y;
	data->player.pos.x += move.x;
}

void	ft_right(t_data *data)
{
	t_vector2	w_check;
	t_vector2	move;

	move = (t_vector2){.y = 0.05 * cos(deg2rad(data->player.direction)),
		.x = 0.05 * sin(deg2rad(data->player.direction))};
	w_check.y = data->player.pos.y + move.y;
	w_check.x = data->player.pos.x - move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1 || data->map_data.int_map[(int)(w_check.y
			- move.y)][(int)(w_check.x + move.x)] == 1)
		return ;
	data->player.pos.y += move.y;
	data->player.pos.x -= move.x;
}

void	ft_backward(t_data *data)
{
	t_vector2	w_check;
	t_vector2	move;

	move = (t_vector2){0.05 * cos(deg2rad(data->player.direction)), 0.05
		* sin(deg2rad(-data->player.direction))};
	w_check.y = data->player.pos.y + move.y;
	w_check.x = data->player.pos.x - move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1 || data->map_data.int_map[(int)(w_check.y
			- move.y)][(int)(w_check.x + move.x)] == 1)
		return ;
	data->player.pos.y += move.y;
	data->player.pos.x -= move.x;
}

void	ft_forward(t_data *data)
{
	t_vector2	w_check;
	t_vector2	move;

	move = (t_vector2){0.05 * cos(deg2rad(data->player.direction)), 0.05
		* sin(deg2rad(-data->player.direction))};
	w_check.y = data->player.pos.y - move.y;
	w_check.x = data->player.pos.x + move.x;
	if (data->map_data.int_map[(int)w_check.y][(int)w_check.x] == 1 || data->map_data.int_map[(int)(w_check.y
			+ move.y)][(int)(w_check.x - move.x)] == 1)
		return ;
	data->player.pos.y -= move.y;
	data->player.pos.x += move.x;
}

void	ft_move(int keycode, t_data *data)
{
	if (keycode == Key_W)
		ft_forward(data);
	else if (keycode == Key_S)
		ft_backward(data);
	else if (keycode == Key_A)
		ft_left(data);
	else if (keycode == Key_D)
		ft_right(data);
}

void	render_window(t_data *data)
{
	double		angle;
	t_ray_data	*ray;
	int			i;

	i = GAMEWIDTH;
	angle = data->player.fov;
	ray = (t_ray_data *)malloc(sizeof(t_ray_data) * GAMEWIDTH);
	mlx_clear_window(data->mlx, data->win);
	clear_img(data);
	draw_outlines(data);
	while (i--)
	{
		ray[i] = calculate_ray(data, angle);
		angle -= data->player.fov / GAMEWIDTH;
	}
	draw_screen2(data, ray);
	draw_screen3(data, ray);
	draw_screen4(data, ray);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	free(ray);
}

int	key_press_func(int keycode, t_data *data)
{
	if (keycode == Key_W || keycode == Key_A || keycode == Key_S
		|| keycode == Key_D)
		ft_move(keycode, data);
	if (keycode == key_rt)
		data->player.direction += 3;
	if (keycode == key_lt)
		data->player.direction -= 3;
	if (data->player.direction >= 360)
		data->player.direction = ft_abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		exit(1);
	render_window(data);
	return (0);
}
